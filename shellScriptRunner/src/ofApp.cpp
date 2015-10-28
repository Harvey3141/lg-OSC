#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    ofSetFrameRate(30);
    setupOSC();
}

//--------------------------------------------------------------
void ofApp::setupOSC(){
	receiver.setup(9020);
}

//--------------------------------------------------------------
void ofApp::update(){
    updateReceiveOSC();
}


void ofApp::updateReceiveOSC () {

	// check for waiting messages
	while(receiver.hasWaitingMessages()){
		// get the next message
		ofxOscMessage m;
		receiver.getNextMessage(&m);

		string address = m.getAddress();
		float value = m.getArgAsFloat(0);
		if (address.find("shellScript") !=std::string::npos && value == 1) {
			std::size_t found = address.find_last_of("/\\");
			string id = address.substr(found+1);
			cout << "Opening shell script called " << id << endl;
			openShellScript(id);
		}
	}
}

//--------------------------------------------------------------
void ofApp::openShellScript (string name) {
	string shPath = name;
	shPath = ofToDataPath(shPath, true );

	char *shPathChar;
	shPathChar = new char[ shPath.length() + 1 ];

	strcpy( shPathChar, shPath.c_str() );

	cout << shPathChar << endl;

	system(shPathChar);

}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
