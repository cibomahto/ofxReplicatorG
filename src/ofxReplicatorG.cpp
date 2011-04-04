#include "ofxReplicatorG.h"
#include <string>

ofxReplicatorG::ofxReplicatorG() {

}

bool ofxReplicatorG::setup(string ip, int _port) {
    return tcpClient.setup(ip, _port);
}

void ofxReplicatorG::send(string message) {
    // TODO: check that we are still connected?

    if(tcpClient.sendRaw(message + "\n")){
        string str = tcpClient.receive();
        if( str.length() > 0 ){
            // TODO: Handle return messages
//            msgRx = str;
        }
    }else if(!tcpClient.isConnected()){
        // TODO: Something here if we aren't connected
    }
}

void ofxReplicatorG::loadFile(string filename) {
    send("{\"command\":\"open\", \"filename\":\"" + filename + "\"}");
}

void ofxReplicatorG::skein() {
    send("{\"command\":\"skein\"}");
}

void ofxReplicatorG::printToFile(string filename) {
    send("{\"command\":\"build\", \"target\":\"file\", \"filename\":\"" + filename + "\"}");
}

void ofxReplicatorG::printToFile(string inputFile, string destinationFile) {
    send("{\"command\":\"printToFile\", \"inputFile\":\"" + inputFile + "\", \"destinationFile\":\"" + destinationFile + "\"}");
}

bool ofxReplicatorG::isConnected() {
    return tcpClient.isConnected();
}
