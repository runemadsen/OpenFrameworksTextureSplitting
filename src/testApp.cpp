#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup()
{	
	//load movie
	player.loadMovie("fingers.mov");
	player.play();
	
	int cellWidth = player.width / 3;
	int cellHeight = player.height / 3;
	int curX = 0;
	int curY = 0;
	
	for(int i = 0; i < NUM_QUADS; i++)
	{
		quads[i].setTextureRect(curX, curY, cellWidth, cellHeight);
		quads[i].setLocation(ofRandom(0, 500), ofRandom(0, 400));
		
		curX += cellWidth;
		
		if( i % 3 == 2)
		{
			curX = 0;
			curY += cellHeight;
		}
	}
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw()
{
	//bind the texture before drawing the quads
	player.getTextureReference().bind();
	
	for (int i=0; i < NUM_QUADS; i++)
	{
		quads[i].draw();
	}
	
	player.getTextureReference().unbind();

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

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

