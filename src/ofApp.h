#pragma once

#include "ofMain.h"
#include "ofxRemoteUIServer.h"

#define STATES C(START)C(IDLE)C(NOT_IDLE)
#define C(x) x,
typedef enum { STATES NUM_STATES } state_t;
#undef C
#define C(x) #x,
const char* const state_names[] = { STATES };

class ofApp : public ofBaseApp{
  public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

    state_t state;
    long state_start_at;
    string cur_state_name;

    void transition(state_t _state) {
      onExitState();
      ofLog() << "transition from " << state_names[state] << " to " << state_names[_state];
      state_start_at = ofGetElapsedTimeMillis();
      state = _state;
      cur_state_name = state_names[state];
      onEnterState();
    }

    long timeInState() {
      return ofGetElapsedTimeMillis() - state_start_at;
    }

    void onEnterState();
    void onExitState();
};
