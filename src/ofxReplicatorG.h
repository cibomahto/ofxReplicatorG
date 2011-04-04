#ifndef OFX_REPLICATORG
#define OFX_REPLICATORG

/************************************************************

OpenFrameworks Library

File: 			ofxReplicatorG.h
Description: 	Remote control for the ReplicatorG 3d printing software
Notes:			Good luck!

Last Modified: 2011.04.04
Creator: Matt Mets

************************************************************/


#include "ofMain.h"
#include "ofxNetwork.h"

class ofxReplicatorG {

	public:
        ofxReplicatorG();

        bool setup(string ip, int _port);

        void loadFile(string fileName);

        void skein();

        void printToFile(string filename);

        void printToFile(string input, string destination);

        bool isConnected();
	private:
        void send(string message);

		ofxTCPClient tcpClient;
};



#endif
