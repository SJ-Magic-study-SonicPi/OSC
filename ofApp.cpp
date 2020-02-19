/************************************************************
************************************************************/
#include "ofApp.h"

/************************************************************
************************************************************/
/******************************
******************************/
ofApp::ofApp()
: Osc("127.0.0.1", 4559, 12345)
{
}

/******************************
******************************/
ofApp::~ofApp()
{
}

/******************************
******************************/
void ofApp::exit()
{
	printf("Good-bye\n");
}

/******************************
******************************/
void ofApp::setup(){
	/********************
	********************/
	ofSetWindowTitle("OSC");
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	ofSetWindowShape(WIDTH, HEIGHT);
	ofSetEscapeQuitsApp(false);
	
	ofEnableAlphaBlending();
	ofEnableBlendMode(OF_BLENDMODE_ALPHA);
	// ofEnableBlendMode(OF_BLENDMODE_ADD);
	// ofEnableSmoothing();
}

/******************************
******************************/
void ofApp::update(){

	/********************
	********************/
	while(Osc.OscReceive.hasWaitingMessages()){
		ofxOscMessage m_receive;
		Osc.OscReceive.getNextMessage(m_receive); // 引数がpointerから参照に変わった.
		
		if(m_receive.getAddress() == "/Hello/World"){
			float val = m_receive.getArgAsFloat(0);
			printf("%f\n", val);
			fflush(stdout);
		}
	}

}

/******************************
******************************/
void ofApp::draw(){
	ofBackground(30);
}

/******************************
OSCの送り方には、OSC messageとOSC bundleがある。
OSC bunfleは、複数のOSC messageをひとまとめにして送るための仕組み。
	http://tips.hecomi.com/entry/2017/08/20/193823

oFでは、ofxOscSender::sendMessage(const ofxOscMessage &message, bool wrapInBundle=true)で、wrapInBundleにて指定可能。
通常、OSC同士や、Unityなどとの連携では、OSC bundleを使っている。

ここで、SonicPi側であるが、v3.1.0の時点で、OSC bundleに対応していないらしい。
なので、明示的に wrapInBundle = false を指定することが必要。
******************************/
void ofApp::keyPressed(int key){
	switch(key){
		case 'a':
		{
			ofxOscMessage m;
			m.setAddress("/trigger");
			m.addFloatArg(60);
			m.addFloatArg(100);
			m.addFloatArg(1.0);
			
			Osc.OscSend.sendMessage(m, /* wrapInBundle */ false);
		}
			break;
	}
}

/******************************
******************************/
void ofApp::keyReleased(int key){

}

/******************************
******************************/
void ofApp::mouseMoved(int x, int y ){

}

/******************************
******************************/
void ofApp::mouseDragged(int x, int y, int button){

}

/******************************
******************************/
void ofApp::mousePressed(int x, int y, int button){

}

/******************************
******************************/
void ofApp::mouseReleased(int x, int y, int button){

}

/******************************
******************************/
void ofApp::mouseEntered(int x, int y){

}

/******************************
******************************/
void ofApp::mouseExited(int x, int y){

}

/******************************
******************************/
void ofApp::windowResized(int w, int h){

}

/******************************
******************************/
void ofApp::gotMessage(ofMessage msg){

}

/******************************
******************************/
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
