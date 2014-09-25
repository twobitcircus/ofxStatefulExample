#include "ofApp.h"

void ofApp::setup(){
  RUI_SETUP();
  RUI_NEW_GROUP("STATE");
  RUI_SHARE_ENUM_PARAM(state, START, NUM_STATES-1, vector<string>(state_names, state_names+NUM_STATES));
  RUI_NEW_GROUP("APPLICATION");
  RUI_LOAD_FROM_XML(); 

  transition(IDLE);
}

void ofApp::update(){
  switch (state) {
    case IDLE:
      if (timeInState() > 2000) {
        transition(NOT_IDLE);
      }
      break;
    case NOT_IDLE:
      if (timeInState() > 2000) {
        transition(IDLE);
      }
      break;
  }
}

void ofApp::onEnterState() {
  switch (state) {
    case IDLE:
      break;
    case NOT_IDLE:
      break;
  }
}

void ofApp::onExitState() {
  switch (state) {
    case IDLE:
      break;
    case NOT_IDLE:
      break;
  }
}

void ofApp::draw(){

}

void ofApp::keyPressed(int key){

}

void ofApp::keyReleased(int key){

}

void ofApp::mouseMoved(int x, int y){

}

void ofApp::mouseDragged(int x, int y, int button){

}

void ofApp::mousePressed(int x, int y, int button){

}

void ofApp::mouseReleased(int x, int y, int button){

}

void ofApp::windowResized(int w, int h){

}

void ofApp::gotMessage(ofMessage msg){

}

void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
