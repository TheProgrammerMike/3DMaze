/*


*/	


#include <stdio.h>
#include "MSGA3D.h"

int count;

bool MyTask(MSGAEngine3D &x,int ,void *)
{
	x.WindowSetCaption("count t=%d",count);
	count = count+1;
	return true;
}
bool Task5(MSGAEngine3D &x,int ,void *)
{
	//	x.AnimatorCollisionResponse(1,28,27);	
	return true;



}

bool MyTask2(MSGAEngine3D &x,int ,void *)
{
	x.SoundStop(77);
	return true;
	
}


int main(void)
 {
	//Startup
	MSGAEngine3D x(800,800,32,true);		// Creates	"x"		engine		(800x x 800y 32bit/pixel
	x.TextureLoad(3,"end.bmp");		// Loads	"3"		Texture		cube.jpg(07DodgeChargerRed)
	x.TextureLoad(6,"Pedestal.bmp");// Loads	"6"		Texture		Pedestal.bmp(CustomDrawing)
	x.TextureLoad(96,"start.bmp");
	//x.TextureLoad(97,"tile.bmp");
	x.TextureLoad(104,"sky_front.jpg");
	x.TextureLoad(99,"sky_left.jpg");
	x.TextureLoad(100,"sky_right.jpg");
	x.TextureLoad(101,"sky_up.jpg");
	x.TextureLoad(102,"sky_back.jpg");
	x.TextureLoad(103,"sky_down.jpg");
	x.NodeLoadSkyBox(10,101,103,104,102,99,100);

//	x.NodeLoadCameraFPS(1);			// Creates	"1"		Camera		FPS											***************************************************
	x.NodeLoadCameraFPS(1,200,500,3000,true);

//	x.AnimatorCollisionResponse(nodeid,targetnode,meshid);

	//Cube2

	x.NodeLoadCube(2,300);			// Creates	"2"		Cube		(300 units squard)
	x.NodeSetTexture(2,3);			// Applies Texture3	to  cube"2"		
	x.AnimatorRotation(2,30,20,-30);// Effect - Rotates  cube2      (30x,20y,-30z)
	x.NodeSetPosition(2,0,200,4000);	// Sets position    cube2		(600 into z)
	
	//Cylinder5 (Mesh4) 
	

	x.MeshLoadCylinder(4,200,100);		//Creates	"4"		Mesh		Cylinder(200 radius,100 height)
	x.NodeLoadMesh(5,4);				//Loads		"5"		Cylinder	200rx100h
	x.NodeSetPosition(5,0,-200,600);	//Set cylinder under Rotating cube creating Pedestal effect.
	x.NodeSetTexture(5,6);				//Applies Texture6 to cylinder5
	x.AnimatorRotation(5,0,1,0);		//Effect - rotate cylinder5 to right (1y)
	x.NodeSetPosition(5,0,-100,4000);

	x.AnimatorCollisionResponse(1,5,4);

	//x.AnimatorCollisionResponse(nodid,targetnode,meshid);
	//x.NodeLoadMesh(nodeID,MeshID)

	//Gate 2 FRW

	x.MeshLoadRectangle(19,200,1000);
	x.NodeLoadMesh(20,19);
	x.NodeSetRotation(20,0,0,90);
	x.NodeSetPosition(20,600,0,400);
//	x.AnimatorCollisionResponse(1,20,19);	

		//FRW B
	x.MeshLoadRectangle(21,200,1000);
	x.NodeLoadMesh(22,21);
	x.NodeSetRotation(22,180,0,90);
	x.NodeSetPosition(22,600,0,400);
//	x.AnimatorCollisionResponse(1,22,21);	


	//Gate 2 FLW
	
	x.MeshLoadRectangle(23,200,1000);
	x.NodeLoadMesh(24,23);
	x.NodeSetRotation(24,0,0,90);
	x.NodeSetPosition(24,-600,0,400);
//	x.AnimatorCollisionResponse(1,24,23);	


		//FLW B
	x.MeshLoadRectangle(25,200,1000);
	x.NodeLoadMesh(26,25);
	x.NodeSetRotation(26,180,0,90);
	x.NodeSetPosition(26,-600,0,400);
//	x.AnimatorCollisionResponse(1,26,25);	


	//SideWall Left

	x.MeshLoadRectangle(27,200,5000);
	x.NodeLoadMesh(28,27);
	x.NodeSetRotation(28,90,0,90);
	x.NodeSetPosition(28,-1100,0,2600);
//	x.AnimatorCollisionResponse(1,28,27);	

	//SideWall Left Back
	x.MeshLoadRectangle(29,200,5000);
	x.NodeLoadMesh(30,29);
	x.NodeSetRotation(30,270,0,90);
	x.NodeSetPosition(30,-1100,0,2600);
//	x.AnimatorCollisionResponse(1,30,29);	

	//SideWall RT
	
	x.MeshLoadRectangle(31,200,5000);
	x.NodeLoadMesh(32,31);
	x.NodeSetRotation(32,90,0,90);
	x.NodeSetPosition(32,1100,0,2600);
//	x.AnimatorCollisionResponse(1,32,31);	

	//SideWall RT Back
	x.MeshLoadRectangle(33,200,5000);
	x.NodeLoadMesh(34,33);
	x.NodeSetRotation(34,270,0,90);
	x.NodeSetPosition(34,1100,0,2600);


	//Gate 4

	x.MeshLoadRectangle(35,200,2000);
	x.NodeLoadMesh(36,35);
	x.NodeSetRotation(36,0,0,90);
	x.NodeSetPosition(36,-100,0,700);
		//FLW B
	x.MeshLoadRectangle(37,200,2000);
	x.NodeLoadMesh(38,37);
	x.NodeSetRotation(38,180,0,90);
	x.NodeSetPosition(38,-100,0,700);



	//Gate 5

	x.MeshLoadRectangle(39,200,2000);
	x.NodeLoadMesh(40,39);
	x.NodeSetRotation(40,0,0,90);
	x.NodeSetPosition(40,100,0,1000);
		//FLW B
	x.MeshLoadRectangle(41,200,2000);
	x.NodeLoadMesh(42,41);
	x.NodeSetRotation(42,180,0,90);
	x.NodeSetPosition(42,100,0,1000);

	
	
	//Gate 6


	x.MeshLoadRectangle(43,200,1800);
	x.NodeLoadMesh(44,43);
	x.NodeSetRotation(44,0,0,90);
	x.NodeSetPosition(44,0,0,1300);
		//FLW B
	x.MeshLoadRectangle(45,200,1800);
	x.NodeLoadMesh(46,45);
	x.NodeSetRotation(46,180,0,90);
	x.NodeSetPosition(46,0,0,1300);


	//Gate 7

	x.MeshLoadRectangle(47,200,600);
	x.NodeLoadMesh(48,47);
	x.NodeSetRotation(48,90,0,90);
	x.NodeSetPosition(48,00,0,1600);

		//G7 Backwall
	x.MeshLoadRectangle(49,200,600);
	x.NodeLoadMesh(50,49);
	x.NodeSetRotation(50,270,0,90);
	x.NodeSetPosition(50,00,0,1600);



	//G8	
	x.MeshLoadRectangle(51,200,900);
	x.NodeLoadMesh(52,51);
	x.NodeSetRotation(52,0,0,90);
	x.NodeSetPosition(52,-650,0,1600);
		//FLW B
	x.MeshLoadRectangle(53,200,900);
	x.NodeLoadMesh(54,53);
	x.NodeSetRotation(54,180,0,90);
	x.NodeSetPosition(54,-650,0,1600);

	

	//G9
	x.MeshLoadRectangle(55,200,900);
	x.NodeLoadMesh(56,55);
	x.NodeSetRotation(56,0,0,90);
	x.NodeSetPosition(56,-450,0,1900);
		//FLW B
	x.MeshLoadRectangle(57,200,900);
	x.NodeLoadMesh(58,57);
	x.NodeSetRotation(58,180,0,90);
	x.NodeSetPosition(58,-450,0,1900);

	//G10
	x.MeshLoadRectangle(59,200,2000);
	x.NodeLoadMesh(60,59);
	x.NodeSetRotation(60,0,0,90);
	x.NodeSetPosition(60,100,0,2200);
		//FLW B
	x.MeshLoadRectangle(61,200,2000);
	x.NodeLoadMesh(62,61);
	x.NodeSetRotation(62,180,0,90);
	x.NodeSetPosition(62,100,0,2200);


	//G11
	x.MeshLoadRectangle(63,200,900);
	x.NodeLoadMesh(64,63);
	x.NodeSetRotation(64,0,0,90);
	x.NodeSetPosition(64,650,0,1600);
		//FLW B
	x.MeshLoadRectangle(65,200,900);
	x.NodeLoadMesh(66,65);
	x.NodeSetRotation(66,180,0,90);
	x.NodeSetPosition(66,650,0,1600);

	//G12
	x.MeshLoadRectangle(67,200,600);
	x.NodeLoadMesh(68,67);
	x.NodeSetRotation(68,90,0,90);
	x.NodeSetPosition(68,-900,0,2200);

		//G12 Backwall
	x.MeshLoadRectangle(69,200,600);
	x.NodeLoadMesh(70,69);
	x.NodeSetRotation(70,270,0,90);
	x.NodeSetPosition(70,-900,0,2200);

	//Gate 13
	x.MeshLoadRectangle(71,200,900);
	x.NodeLoadMesh(72,71);
	x.NodeSetRotation(72,0,0,90);
	x.NodeSetPosition(72,450,0,1900);
		//FLW B
	x.MeshLoadRectangle(73,200,900);
	x.NodeLoadMesh(74,73);
	x.NodeSetRotation(74,180,0,90);
	x.NodeSetPosition(74,450,0,1900);


	//Gate 14
	x.MeshLoadRectangle(75,200,1500);
	x.NodeLoadMesh(76,75);
	x.NodeSetRotation(76,0,0,90);
	x.NodeSetPosition(76,-150,0,2800);
		//FLW B
	x.MeshLoadRectangle(77,200,1500);
	x.NodeLoadMesh(78,77);
	x.NodeSetRotation(78,180,0,90);
	x.NodeSetPosition(78,-150,0,2800);



	//Gate 15
	x.MeshLoadRectangle(79,200,1500);
	x.NodeLoadMesh(80,79);
	x.NodeSetRotation(80,0,0,90);
	x.NodeSetPosition(80,100,0,2500);
		//FLW B
	x.MeshLoadRectangle(81,200,1500);
	x.NodeLoadMesh(82,81);
	x.NodeSetRotation(82,180,0,90);
	x.NodeSetPosition(82,100,0,2500);


	//Gate 16
	x.MeshLoadRectangle(83,200,600);
	x.NodeLoadMesh(84,83);
	x.NodeSetRotation(84,90,0,90);
	x.NodeSetPosition(84,850,0,2800);

		//G12 Backwall
	x.MeshLoadRectangle(85,200,600);
	x.NodeLoadMesh(86,85);
	x.NodeSetRotation(86,270,0,90);
	x.NodeSetPosition(86,850,0,2800);



	//Gate 17
	x.MeshLoadRectangle(87,200,1950);
	x.NodeLoadMesh(88,87);
	x.NodeSetRotation(88,0,0,90);
	x.NodeSetPosition(88,-125,0,3100);
		//FLW B
	x.MeshLoadRectangle(89,200,1950);
	x.NodeLoadMesh(90,89);
	x.NodeSetRotation(90,180,0,90);
	x.NodeSetPosition(90,-125,0,3100);


	//gate 18
	x.MeshLoadRectangle(91,200,2000);
	x.NodeLoadMesh(92,91);
	x.NodeSetRotation(92,0,0,90);
	x.NodeSetPosition(92,100,0,3400);
		//FLW B
	x.MeshLoadRectangle(93,200,2000);
	x.NodeLoadMesh(94,93);
	x.NodeSetRotation(94,180,0,90);
	x.NodeSetPosition(94,100,0,3400);

	//Gate19 FRW
	x.MeshLoadRectangle(6,200,1000);
	x.NodeLoadMesh(7,6);
	x.NodeSetRotation(7,0,0,90);
	x.NodeSetPosition(7,600,0,3700);
		//FRW B
	x.MeshLoadRectangle(13,200,1000);
	x.NodeLoadMesh(14,13);
	x.NodeSetRotation(14,180,0,90);
	x.NodeSetPosition(14,600,0,3700);


	//Gate20 FLW
	x.MeshLoadRectangle(10,200,1000);
	x.NodeLoadMesh(11,10);
	x.NodeSetRotation(11,0,0,90);
	x.NodeSetPosition(11,-600,0,3700);

		//FLW B 
	x.MeshLoadRectangle(17,200,1000);
	x.NodeLoadMesh(18,17);
	x.NodeSetRotation(18,180,0,90);
	x.NodeSetPosition(18,-600,0,3700);



	x.NodeLoadBillboard(12,300,300);
	x.NodeSetPosition(12,0,0,300);
	x.NodeSetTexture(12,96);

	x.SoundLoad(77,"song.mp3");
	x.SoundPlay(77,0,0,0,true);

	x.WindowSetCaption("3D Maze");


	
//x.TaskLoad(7891,50,true, Task5);
	
//	x.TaskLoad(200,50,true, Task5);
//	x.NodeLoadSkyBox(10,101,103,104,102,99,100);


/*	
	x.MeshLoadRectangle(911,1000,1000);
	x.NodeLoadWater(911,911);
	x.NodeSetRotation(911,90,0,0);
	x.NodeSetTexture(911,3);

	x.WindowSetCaption("Hel %d",123);

	x.SoundLoad(77,"Kanye West - Stronger.mp3");
	x.SoundPlay(77,0,0,0); //can be true for allover 3d sound if 91,true - continuous song.

	x.TaskLoad(91,50,true, MyTask);
	x.TaskLoad(92,5000,false,MyTask2);
	

*/	
	x.GameLoop();					// Initiates rendering ~65hz {***MUST BE AT END***} 
	return 0;
 }

