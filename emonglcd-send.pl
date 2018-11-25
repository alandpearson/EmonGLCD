#!/usr/bin/perl -w

# Send data to emonGLCD wireless power display device
# Subscribes to MQTT topic from emonhub, listens for updates to
# the utility power and solar readings, and then sends them via 
# emonhub/RF to emonGLCD units

use Net::MQTT::Simple;
use Net::MQTT::Simple::Auth;
use POSIX  'strftime';
use Config::Simple;

use File::Basename qw(dirname);
use Cwd  qw(abs_path);
use lib dirname(dirname abs_path $0) . '/libs/perl';

use HomeAutomation ;




my $mqtt ; 
my $nodeId = 0 ;
my $mqttMsg = "0" ;
my %mqttData = () ;
my $utilityW = 0 ;
my $solarW = 0 ;
my $utilityKwh = 0 ;
my $solarKwh = 0 ;
my $lastSend = 0 ;	#when we last sent to emonglcd
my $sendInterval = 15 ; #only send max every $sendInterval secs



my $cfg = new Config::Simple('/etc/emonglcd-send.cfg') ;


#MQTT params
my $mqttTopic = $cfg->param('mqtt_pub_topic') ;


my $debug = $cfg->param('debug') ;


sub sendToEmonglcd {
	
	my ($solarW, $utilityW) = @_ ;
	my $mqttValues = "0" ;



	#Send the time

	my $hour = strftime('%H', localtime) ;
	my $min = strftime('%M', localtime) ;
	my $sec = strftime('%S', localtime) ;

	$mqttValues= "$hour," . "$min," . "$sec," . "$utilityW," . "$solarW," . "$utilityKwh," . "$solarKwh" ;  
	
	if ($debug) {
		print "sendToemonglcd: Creating MQTT payload for emonglcd : $mqttValues \n";
	}

	return $mqttValues ;

}





sub msgRecv {

	my  ($topic, $msg) = @_ ;

	my $sendNow = 0 ;

	if ($debug) {
		print "MQTT: topic $topic sent payload ($msg) \n" ;
	}


	if ($topic eq $cfg->param('mqtt_sub_utilityW') ) {
		$utilityW = $msg * 1000;
		$sendNow = 1;
	} elsif ($topic eq $cfg->param('mqtt_sub_utilityKwh') ) {
		#multiply by 100 so we only send ints
		$utilityKwh = $msg * 100 ;
		$sendNow = 0;
	} elsif ($topic eq $cfg->param('mqtt_sub_solarW') ) {
		$solarW = $msg ;
		$sendNow = 1;
	} elsif ($topic eq $cfg->param('mqtt_sub_solarKwh') ) {
		#multiply by 100 so we only send ints
		$solarKwh = $msg * 100 ;
		$sendNow = 0;
	}


	# build the mqtt payload
	$mqttData{msg} = sendToEmonglcd($solarW,$utilityW,$solarKwh,$utilityKwh) ;


	if ( time() - $sendInterval > $lastSend || $sendNow) {
		# Set MQTT topic to emonhub/tx/<nodeid>/values  for TX by emonpi

		foreach my $emonglcdNodeId (split (',', $cfg->param('emonglcd_nodeid')) ) {
			$mqttTopic =  $mqttTopic . "/" . $emonglcdNodeId ."/values" ;
			HomeAutomation::mqttSend(\$mqtt, $mqttTopic, %mqttData) ;
			$lastSend = time() ;
			if ($debug) {
				print "msgRecv $mqttData{msg} sent to emonglcd node $emonglcdNodeId \n" ;
			}
		}
	}
	

	return ;
}




#########################################################################################################################
# Main															#
#########################################################################################################################


if ($debug) {
	print "Emonglcd updater started. \n" ;
	print "Connecting to MQTT broker..\n" ;
}

# MQTT Connect 
$mqtt = Net::MQTT::Simple::Auth->new($cfg->param('mqtt_hostname'), $cfg->param('mqtt_user'), $cfg->param('mqtt_pass') );

if ( $mqtt ) {
	
	if ($debug) {
		print ("MQTT connected to broker " . $cfg->param('mqtt_hostname') . "\n") ;
	}
	$mqtt->subscribe($cfg->param('mqtt_sub_solarW'), \&msgRecv) ; 
	$mqtt->subscribe($cfg->param('mqtt_sub_utilityW'), \&msgRecv) ; 
	$mqtt->subscribe($cfg->param('mqtt_sub_solarKwh'), \&msgRecv) ; 
	$mqtt->subscribe($cfg->param('mqtt_sub_utilityKwh'), \&msgRecv) ; 
	$mqtt->run() ;
} else {
	print ("MQTT ERROR could not connect to broker " . $cfg->param('mqtt_hostname') . "\n") ;
}



exit () ;
