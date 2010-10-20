/*
 *  VideoQuad.h
 *  videoSplitter
 *
 *  Created by Brett Renfer on 10/19/10.
 *  Copyright 2010 Robotconscience. All rights reserved.
 *
 */

#pragma once
#include "ofQuad.h"

class VideoQuad
{
	
public:
	
	void setTextureRect(float x, float y, int w, int h)
	{
		texCoords[0] = x;
		texCoords[1] = y;
		
		texCoords[2] = x + w;
		texCoords[3] = y;
		
		texCoords[4] = x + w;
		texCoords[5] = y + h;
		
		texCoords[6] = x;
		texCoords[7] = y + h;
		
		rect.x = x;
		rect.y = y;
		rect.width = w;
		rect.height = h;
	};
	
	// need to call setTextureRect before this
	void setLocation(float x, float y)
	{
		points[0].x = x;
		points[0].y = y;
		
		points[1].x = x + rect.width;
		points[1].y = y;
		
		points[2].x = x  + rect.width;
		points[2].y = y  + rect.height;
		
		points[3].x = x;
		points[3].y = y  + rect.height;
	}
	
	//make sure to bind() something first!
	void draw()
	{
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glTexCoordPointer(2, GL_FLOAT, 0, &texCoords[0]);
		ofQuad3D(points[0], points[1], points[2], points[3]);
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	}
	
protected:
	
	ofPoint points[4];
	float texCoords[8];
	
	ofRectangle rect;
};