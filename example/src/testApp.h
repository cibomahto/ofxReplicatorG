#ifndef _TEST_APP
#define _TEST_APP





#include "ofMain.h"
#include "ofxNetwork.h"
#include "ofxReplicatorG.h"

class testApp : public ofBaseApp{

	public:

		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);

        int port;

//		ofxTCPClient tcpClient;
        ofxReplicatorG printer;

		string msgTx, msgRx;

		ofTrueTypeFont  mono;
		ofTrueTypeFont  monosm;

		float counter;
		int connectTime;
		int deltaTime;

		int size;
		int pos;
		bool typed;

		// Move these somewhere else??/
		void send(string message);
		string lastMessage;
};

#endif

