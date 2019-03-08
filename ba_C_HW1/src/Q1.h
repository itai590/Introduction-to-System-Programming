/*
 * C_HW1
 * Q1.h
 *
 *  Created on: Nov 16, 2018
 *      Author: itai
 */

#ifndef Q1_H_
#define Q1_H_

#define Q1_SIZE 4

#define Q1_SWITCH_FLIP_90_CW 1
#define Q1_SWITCH_FLIP_90_CCW 2
#define Q1_SWITCH_FLIP_HORIZONTAL 3
#define Q1_SWITCH_FLIP_VERTICAL 4
#define Q1_SWITCH_QUIT -1
#define Q1_SWITCH_INIT 0


#define Q1_MENU "\n\nPlease choose one of the following options:\n1 -90 degree clockwise\n2 -90 degree counter clockwise\n3 -Flip Horizontal\n4 -Flip Vertical\n-1 -Quit\n"
#define AFTER_MANIPULATION_MSG "\n--------- picture after manipulation ---------"


void flipHorizontal(int* arr, int row, int col);
void flipVertical(int* arr, int row, int col);
void flip90Clockwise(int* arr, int row, int col);
void flip90Cclockwise(int* arr, int row, int col);

void PictureManipulation(int row, int col);

#endif /* Q1_H_ */
