#include "testApp.h"

#define RECONNECT_TIME 400

//--------------------------------------------------------------
void testApp::setup(){

	// we don't want to be running to fast
	ofSetVerticalSync(true);

	//load our type
	mono.loadFont("type/mono.ttf",9);
	monosm.loadFont("type/mono.ttf",8);

	//some variables

	//have we typed
	typed	= false;

	//our typing position
	pos		= 0;

	//our send and recieve strings
	msgTx	= "";
	msgRx	= "";

	port = 2000;
	lastMessage = "";

	//are we connected to the server - if this fails we
	//will check every few seconds to see if the server exists
	printer.setup("127.0.0.1", port);

	connectTime = 0;
	deltaTime = 0;
}

//--------------------------------------------------------------
void testApp::update(){
	ofBackground(230, 230, 230);

	//we are connected - lets send our text and check what we get back
	if(printer.isConnected()){

	}else{
		//if we are not connected lets try and reconnect every 5 seconds
		deltaTime = ofGetElapsedTimeMillis() - connectTime;

		if( deltaTime > 5000 ){
			printer.setup("127.0.0.1", port);
			connectTime = ofGetElapsedTimeMillis();
		}

	}
}

//--------------------------------------------------------------
void testApp::draw(){

	ofSetColor(20, 20, 20);
	mono.drawString("ReplicatorG Print Example", 15, 30);
	mono.drawString("Press b to print a file", 15, 55);

	if(typed){
		monosm.drawString("sending:", 15, 200);
		monosm.drawString(msgTx, 85, 200);
	}
	else{
		if(printer.isConnected())monosm.drawString("status: type a valid selection to control the printer" + port, 15, 200);
		else monosm.drawString("status: server not found. launch server app and check ports!\n\nreconnecting in "+ofToString( (5000 - deltaTime) / 1000 )+" seconds", 15, 200);
	}

	monosm.drawString("from server: \n"+msgRx, 15, 270);

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

    // Let's try making a command
    lastMessage = "key pressed! ";
    lastMessage.append(1, (char) key);

    switch((char)key) {
        case 'b':
            printer.printToFile("/home/matt/MakerBot/repg_workspace/ReplicatorG/examples/Snake.stl", "/home/matt/Desktop/snake.s3g");
            break;
        case 'l':
            printer.loadFile("/home/matt/MakerBot/repg_workspace/ReplicatorG/examples/Snake.stl");
            break;
        case 's':
            printer.skein();
            break;
        case 'p':
            printer.printToFile("/home/matt/Desktop/snake.s3g");
            break;
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){


}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

