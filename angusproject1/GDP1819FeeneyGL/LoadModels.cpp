#include "globalOpenGLStuff.h"
#include "globalStuff.h"		// for g_pRogerRabbit

#include "cVAOMeshManager.h"
#include "cMeshObject.h"

#include "DebugRenderer/cDebugRenderer.h"

#include <iostream>

// Loading models was moved into this function
void LoadModelTypes( cVAOMeshManager* pTheVAOMeshManager, GLuint shaderProgramID )
{
	sModelDrawInfo bunnyInfo;
	//bunnyInfo.meshFileName = "bun_res3_xyz.ply";
	//bunnyInfo.meshFileName = "bun_res3_xyz_n_uv.ply";	// NOW, WITH NORMALS!!
	bunnyInfo.meshFileName = "bun_zipper_hi_res_xyz_n_smartUVBlender.ply";	// NOW, WITH NORMALS!!
	if ( ! pTheVAOMeshManager->LoadModelIntoVAO(bunnyInfo, shaderProgramID) )
	{
		std::cout << "Didn't load the bunny" << std::endl;
		std::cout << pTheVAOMeshManager->GetLastError() << std::endl;
	}

	sModelDrawInfo airplaneInfo;
	airplaneInfo.meshFileName = "ssj100_xyz_n_GARBAGE_uv.ply";			// "ssj100_xyz.ply";
	pTheVAOMeshManager->LoadModelIntoVAO(airplaneInfo, shaderProgramID);

	//sModelDrawInfo backToTheFuture;
	//backToTheFuture.meshFileName = "de--lorean_xyz_n_GARBAGE_uv.ply";	// "de--lorean.ply";
	//pTheVAOMeshManager->LoadModelIntoVAO(backToTheFuture, shaderProgramID);

	sModelDrawInfo migInfo;
	migInfo.meshFileName = "mig29_xyz_n_GARBAGE_uv.ply";					// "mig29_xyz.ply";
	pTheVAOMeshManager->LoadModelIntoVAO(migInfo, shaderProgramID);

	sModelDrawInfo teapotInfo;
	teapotInfo.meshFileName = "Utah_Teapot_xyz_n_GARBAGE_uv.ply";			// "Utah_Teapot_xyz.ply";
	pTheVAOMeshManager->LoadModelIntoVAO(teapotInfo, shaderProgramID);

	sModelDrawInfo fishInfo;
	fishInfo.meshFileName = "PacificCod0_rotated_xyz_n_GARBAGE_uv.ply";		// "PacificCod0_rotated_xyz.ply";
	pTheVAOMeshManager->LoadModelIntoVAO(fishInfo, shaderProgramID);

	sModelDrawInfo terrainInfo;
	//terrainInfo.meshFileName = "metropolis.ply";	// "MeshLab_Fractal_Terrain_xyz.ply";
	//terrainInfo.meshFileName = "3d_modelC.ply";	// "MeshLab_Fractal_Terrain_xyz.ply";
	//terrainInfo.meshFileName = "mountainterrain.ply";	// "MeshLab_Fractal_Terrain_xyz.ply";
	terrainInfo.meshFileName = "MeshLab_Fractal_Terrain_xyz_n_uv.ply";	// "MeshLab_Fractal_Terrain_xyz.ply";
	// Will alow me to update the vertex data in the mesh
	terrainInfo.bVertexBufferIsDynamic = true;

	pTheVAOMeshManager->LoadModelIntoVAO(terrainInfo, shaderProgramID);

	sModelDrawInfo trackInfo;
	trackInfo.meshFileName = "racetrackv2.ply";
	trackInfo.bVertexBufferIsDynamic = true;
	pTheVAOMeshManager->LoadModelIntoVAO(trackInfo, shaderProgramID);

	sModelDrawInfo carInfo;
	carInfo.meshFileName = "car.ply";
	pTheVAOMeshManager->LoadModelIntoVAO(carInfo, shaderProgramID);

	sModelDrawInfo frigateInfo;
	frigateInfo.meshFileName = "CyclopsFrigate.ply";
	pTheVAOMeshManager->LoadModelIntoVAO(frigateInfo, shaderProgramID);

	sModelDrawInfo destroyerInfo;
	destroyerInfo.meshFileName = "OxossiDestroyer.ply";
	pTheVAOMeshManager->LoadModelIntoVAO(destroyerInfo, shaderProgramID);

	sModelDrawInfo beaconInfo;
	beaconInfo.meshFileName = "beacons.ply";
	pTheVAOMeshManager->LoadModelIntoVAO(beaconInfo, shaderProgramID);

	sModelDrawInfo heliosInfo;
	heliosInfo.meshFileName = "HeliosFrigate2.ply";
	pTheVAOMeshManager->LoadModelIntoVAO(heliosInfo, shaderProgramID);

	sModelDrawInfo asteroidInfo;
	asteroidInfo.meshFileName = "AsteroidStation.ply";
	pTheVAOMeshManager->LoadModelIntoVAO(asteroidInfo, shaderProgramID);

	sModelDrawInfo sphereInfo;
	sphereInfo.meshFileName = "Sphere_320_faces_xyz_n_GARBAGE_uv.ply";			// "Sphere_320_faces_xyz.ply";
	pTheVAOMeshManager->LoadModelIntoVAO(sphereInfo, shaderProgramID);

	sModelDrawInfo sphereInvertedNormalsInfo;
	sphereInvertedNormalsInfo.meshFileName = "Sphere_320_faces_xyz_n_GARBAGE_uv_INVERTED_NORMALS.ply";			// "Sphere_320_faces_xyz.ply";
	pTheVAOMeshManager->LoadModelIntoVAO(sphereInvertedNormalsInfo, shaderProgramID);

	sModelDrawInfo lonelyTri;
	lonelyTri.meshFileName = "singleTriangle_xyz_n.ply";			// "singleTriangle_xyz.ply";
	pTheVAOMeshManager->LoadModelIntoVAO(lonelyTri, shaderProgramID);

	sModelDrawInfo cube1x1x1;
	cube1x1x1.meshFileName = "cube_flat_shaded_xyz_n_uv.ply";			// "cube_flat_shaded_xyz.ply";
	pTheVAOMeshManager->LoadModelIntoVAO(cube1x1x1, shaderProgramID);


	//sModelDrawInfo oldhouse;
	//oldhouse.meshFileName = "Old_House_Combined_xyz_n.ply";		
	//pTheVAOMeshManager->LoadModelIntoVAO(oldhouse, shaderProgramID);

	sModelDrawInfo skyPirate;
	skyPirate.meshFileName = "Sky_Pirate_Combined_xyz_n_BlenderSmart_uv.ply";		
	if ( pTheVAOMeshManager->LoadModelIntoVAO(skyPirate, shaderProgramID) )
	{
		std::cout << "Sky Pirate is loaded" << std::endl;
	}

	// At this point, mesh in in GPU
	std::cout << "Mesh was loaded OK" << std::endl;


	sModelDrawInfo smokeObject;
	smokeObject.meshFileName = "1x1_Star_1_Quad_2_Sided_xyz_n_uv.ply";		
	pTheVAOMeshManager->LoadModelIntoVAO(smokeObject, shaderProgramID);


	// Load the textures, too
	::g_pTheTextureManager->SetBasePath("assets/textures");

	if ( ! ::g_pTheTextureManager->Create2DTextureFromBMPFile("Justin.bmp", true ) )
	{
		std::cout << "Didn't load texture" << std::endl;
	}
	::g_pTheTextureManager->Create2DTextureFromBMPFile("grass.bmp", true );
	::g_pTheTextureManager->Create2DTextureFromBMPFile("brick-wall.bmp", true );
	::g_pTheTextureManager->Create2DTextureFromBMPFile("220px-Emma_Watson_2013.bmp", true );
	::g_pTheTextureManager->Create2DTextureFromBMPFile("Flowers.bmp", true );
	::g_pTheTextureManager->Create2DTextureFromBMPFile("Smoke_1.bmp", true );

	if ( ::g_pTheTextureManager->Create2DTextureFromBMPFile("rock_cave_stylized_height.bmp", true ) )
	{
		std::cout << "loaded height map, too" << std::endl;
	}

	// Load the cube map
	::g_pTheTextureManager->SetBasePath("assets/textures/cubemaps");
	std::string errorString;
	//if ( ::g_pTheTextureManager->CreateCubeTextureFromBMPFiles("CityCubeMap", 
	//	 "city_lf.bmp", "city_rt.bmp",				// reverse these
	//	 "city_dn.bmp", "city_up.bmp",				// Rotate the image "right 90 degrees")
	//	 "city_ft.bmp", "city_bk.bmp", true, errorString ) )
	//{
	//	std::cout << "Loaded the city cube map OK" << std::endl;
	//}
	//else
	//{
	//	std::cout << "Error: city cube map DIDN't load. On no!" << std::endl;
	//}
	if ( ::g_pTheTextureManager->CreateCubeTextureFromBMPFiles("CityCubeMap", 
		 "SpaceBox_right1_posX.bmp", "SpaceBox_left2_negX.bmp", 
		 "SpaceBox_top3_posY.bmp", "SpaceBox_bottom4_negY.bmp", 
		 "SpaceBox_front5_posZ.bmp", "SpaceBox_back6_negZ.bmp", true, errorString ) )
	{
		std::cout << "Loaded the city cube map OK" << std::endl;
	}
	else
	{
		std::cout << "Error: city cube map DIDN't load. On no!" << std::endl;
	}
	//if ( ::g_pTheTextureManager->CreateCubeTextureFromBMPFiles("CityCubeMap", 
	//	 "TropicalSunnyDayLeft2048.bmp", "TropicalSunnyDayRight2048.bmp",		// Alternate these
	//	 "TropicalSunnyDayDown2048.bmp", "TropicalSunnyDayUp2048.bmp", 			// Rotate these 90 degrees
	//	 "TropicalSunnyDayFront2048.bmp", "TropicalSunnyDayBack2048.bmp", true, errorString ) )
	//{
	//	std::cout << "Loaded the city cube map OK" << std::endl;
	//}
	//else
	//{
	//	std::cout << "Error: city cube map DIDN't load. On no!" << std::endl;
	//}


	return;
}

// This is not a good place to put this, but it's near the LoadModels...
//extern cDebugRenderer* g_pDebugRenderer;// = NULL;


	
// Loads the models we are drawing into the vector
void LoadModelsIntoScene(cVAOMeshManager* pTheVAOMeshManager, std::vector<cMeshObject*> &vec_pObjectsToDraw )
{
	//cMeshObject teapot;									// Stack
	//teapot.position = glm::vec3( -3.0f, 0.0f, 0.0f );
	//teapot.objColour = glm::vec3( 1.0f, 0.0f, 0.0f );
	//teapot.meshName =  "Utah_Teapot_xyz.ply";
	//teapot.nonUniformScale = glm::vec3(0.005f,0.005f,0.005f);
	//vecObjectsToDraw.push_back( teapot );		// [1]

	//std::vector< cMeshObject* > vec_pObjectsToDraw;
	{
		cMeshObject* pTeapot = new cMeshObject();
		pTeapot->position = glm::vec3( -40.0f, 0.0f, 0.0f );
		pTeapot->setMeshOrientationEulerAngles( glm::vec3( -90.0f, 0.0f, 0.0f), true );
//		pTeapot->objColour = glm::vec3( 1.0f, 0.0f, 0.0f );
		pTeapot->setDiffuseColour( glm::vec3( 1.0f, 0.0f, 0.0f ) );

		// 50% transparent
		// (from 0 to 1, where 0 is invisible)
		pTeapot->setAlphaTransparency( 0.5f );

		// Make the terrain really shinny...
		pTeapot->setSpecularPower( 100.0f );

		pTeapot->meshName = "Utah_Teapot_xyz_n_GARBAGE_uv.ply";		// "Utah_Teapot_xyz.ply";
		// Note scale...
//		pTeapot->nonUniformScale = glm::vec3(0.005f,0.005f,0.005f);
		pTeapot->setUniformScale( 0.5f );
		// Set the debug renderer here

		// Texture on the teapot
		sTextureInfo grassTexture;
		grassTexture.name = "grass.bmp";
		grassTexture.strength = 1.0f;
		pTeapot->vecTextures.push_back( grassTexture );

		pTeapot->pDebugRenderer = ::g_pDebugRenderer;

		//vec_pObjectsToDraw.push_back( pTeapot );
	}

	{
		cMeshObject* pCod = new cMeshObject();
		pCod->position = glm::vec3( +3.0f, 0.0f, 0.0f );
//		pCod->preRotation = glm::vec3( glm::radians(90.0f), 0.0f, 0.0f );

		pCod->setMeshOrientationEulerAngles( glm::vec3( glm::radians(90.0f), 0.0f, 0.0f ), false );

//		pCod->objColour = glm::vec3( 0.0f, 1.0f, 0.0f );
		pCod->setDiffuseColour( glm::vec3(0.0f, 1.0f, 0.0f) );
		pCod->meshName = "PacificCod0_rotated_xyz_n_GARBAGE_uv.ply";		// "PacificCod0_rotated_xyz.ply";
		pCod->setUniformScale( 10.0f );
			
		pCod->pDebugRenderer = ::g_pDebugRenderer;

		sTextureInfo justin;
		justin.name = "Justin.bmp";
		justin.strength = 1.0f;
		pCod->vecTextures.push_back( justin );



		// Note scale...
		//vec_pObjectsToDraw.push_back( pCod );
	}

	{
		cMeshObject* pCar = new cMeshObject();
		pCar->position = glm::vec3( 0.0f, 20.0f, -20.0f );
//		pCar->objColour = glm::vec3( 0.0f, 0.0f, 1.0f );
		pCar->setDiffuseColour( glm::vec3(0.0f, 0.0f, 1.0f) );
		//
		pCar->setAlphaTransparency( 0.2f );
		// 
		pCar->meshName = "de--lorean_xyz_n_GARBAGE_uv.ply";		// "de--lorean.ply";
		pCar->setUniformScale( 0.5f );
		pCar->pDebugRenderer = ::g_pDebugRenderer;

		sTextureInfo flowers;
		flowers.name = "Flowers.bmp";
		flowers.strength = 1.0f;
		pCar->vecTextures.push_back( flowers );

		sTextureInfo justin;
		justin.name = "Justin.bmp";
		justin.strength = 0.0f;
		pCar->vecTextures.push_back( justin );


		//vec_pObjectsToDraw.push_back( pCar );
	}

	{
		cMeshObject* pMig = new cMeshObject();
		pMig->position = glm::vec3( 0.0f, -3.0f, 0.0f );
//		pMig->objColour = glm::vec3( 0.1f, 0.5f, 0.31f );
		pMig->setDiffuseColour( glm::vec3(0.1f, 0.5f, 0.31f) );
		pMig->nonUniformScale = glm::vec3(9.0f, 9.0f, 9.0f);
		pMig->meshName = "mig29_xyz_n_GARBAGE_uv.ply";			// "mig29_xyz.ply";
		//pMig->meshName = "mig29_xyz_n_GARBAGE_uv.ply";			// "mig29_xyz.ply";
		//pMig->bIsWireFrame = true;
		pMig->pDebugRenderer = ::g_pDebugRenderer;
		// Note scale...
		//vec_pObjectsToDraw.push_back( pMig );
	}

	//cMeshObject* pRogerRabbit = NULL;

	{
		//cMeshObject* pBunny = new cMeshObject();
		::g_pRogerRabbit = new cMeshObject();
//		::g_pRogerRabbit->preRotation = glm::vec3( 0.0f, 0.0f, 0.0f );
		::g_pRogerRabbit->position = glm::vec3(  0.0f, 25.0f, 0.0f );
		//::g_pRogerRabbit->postRotation = glm::vec3( glm::radians(45.0f), 0.0f, 0.0f );

		::g_pRogerRabbit->setMeshOrientationEulerAngles( glm::vec3( glm::radians(45.0f), 0.0f, 0.0f ) );

//		::g_pRogerRabbit->nonUniformScale = glm::vec3(9.0f, 9.0f, 9.0f);
		::g_pRogerRabbit->setUniformScale( 5.0f );
//		::g_pRogerRabbit->objColour = glm::vec3( 1.0f, 1.0f, 0.0f );
//		::g_pRogerRabbit->setDiffuseColour( glm::vec3(1.0f, 1.0f, 0.0f) );
		::g_pRogerRabbit->bUseVertexColour = true;

		// Make the terrain really shinny...
		::g_pRogerRabbit->setSpecularPower( 10.0f );
//		::g_pRogerRabbit->setSpecularColour( glm::vec3(1.0f, 0.0f, 0.0f) );
//		::g_pRogerRabbit->setSpecularPower( 0.54f );


		// "Gold" bunny?
		::g_pRogerRabbit->setDiffuseColour( glm::vec3(1.0f, 223.0f/255.0f, 0.0f) );
		::g_pRogerRabbit->bUseVertexColour = false;
		// Taken from: https://docs.unrealengine.com/en-us/Engine/Rendering/Materials/PhysicallyBased
		// Note that the specular HIGHLIGHT colour is DIFFERENT from 
		// the diffuse... 
		::g_pRogerRabbit->setSpecularPower( 100.0f );
		::g_pRogerRabbit->setSpecularColour( glm::vec3(1.000f, 0.766f, 0.336f) );

		

//		::g_pRogerRabbit->meshName = "bun_res3_xyz.ply";
		::g_pRogerRabbit->meshName = "bun_zipper_hi_res_xyz_n_smartUVBlender.ply";
		::g_pRogerRabbit->bIsVisible = true;
		// 
		::g_pRogerRabbit->friendlyName = "Roger";

		::g_pRogerRabbit->pDebugRenderer = ::g_pDebugRenderer;


		sTextureInfo flowers;
		flowers.name = "Flowers.bmp";
		flowers.strength = 1.0f;
		::g_pRogerRabbit->vecTextures.push_back( flowers );

		sTextureInfo justin;
		justin.name = "Justin.bmp";
		justin.strength = 0.0f;
		::g_pRogerRabbit->vecTextures.push_back( justin );


		//vec_pObjectsToDraw.push_back( ::g_pRogerRabbit );
	}
	int indexSelectedObject = 0;
	{
		cMeshObject* pBunny = new cMeshObject();
//		pBunny->preRotation = glm::vec3( 0.0f, 0.0f, 0.0f );

		pBunny->setMeshOrientationEulerAngles( glm::vec3( 0.0f, 0.0f, 0.0f ) );

		pBunny->position = glm::vec3(  0.0f, 25.0f, 0.0f );
//		pBunny->postRotation = glm::vec3( glm::radians(45.0f), 0.0f, 0.0f );
		pBunny->nonUniformScale = glm::vec3(9.0f, 9.0f, 9.0f);
//		pBunny->objColour = glm::vec3( 1.0f, 1.0f, 0.0f );
		pBunny->setDiffuseColour( glm::vec3(1.0f, 1.0f, 0.0f) );
		pBunny->meshName = "bun_zipper_hi_res_xyz_n_smartUVBlender.ply";
		pBunny->bIsVisible = true;
		pBunny->friendlyName = "Bugs";

		pBunny->pDebugRenderer = ::g_pDebugRenderer;

		//vec_pObjectsToDraw.push_back( pBunny );
	}


	{
		cMeshObject* pTerrain = new cMeshObject();
		pTerrain->position = glm::vec3(  0.0f, 0.0f, 0.0f );
//		pTerrain->objColour = glm::vec3( 1.0f, 1.0f, 1.0f );
//		pTerrain->setDiffuseColour( glm::vec3(1.0f, 1.0f, 1.0f) );
		pTerrain->setDiffuseColour( glm::vec3(0.0f, 0.0f, 0.0f) );
		
		// Make the terrain really shinny...
		pTerrain->setSpecularPower( 100.0f );


		pTerrain->bUseVertexColour = false;
//		pTerrain->u
		//pTerrain->meshName = "metropolis.ply";		// "MeshLab_Fractal_Terrain_xyz.ply";
		//pTerrain->meshName = "mountainterrain.ply";		// "MeshLab_Fractal_Terrain_xyz.ply";
		pTerrain->meshName = "MeshLab_Fractal_Terrain_xyz_n_uv.ply";		// "MeshLab_Fractal_Terrain_xyz.ply";
		pTerrain->friendlyName = "The Terrain";
		//pTerrain->bIsWireFrame = true;
		pTerrain->bIsVisible = true;
		pTerrain->bIsUpdatedByPhysics = true;

		pTerrain->pDebugRenderer = ::g_pDebugRenderer;

		sBox* pBox = new sBox();
		sModelDrawInfo cube;
		cube.meshFileName = pTerrain->meshName;
		pTheVAOMeshManager->FindDrawInfoByModelName(cube);

		for (int i = 0; i < cube.numberOfTriangles; i++)
		{
			sTriangle* pTri = new sTriangle();
			pTri->v[0] = glm::vec3(cube.pVerticesFromFile[cube.pTriangles[i].vertex_index_1].x, cube.pVerticesFromFile[cube.pTriangles[i].vertex_index_1].y, cube.pVerticesFromFile[cube.pTriangles[i].vertex_index_1].z);
			//pTri->v[0] = glm::vec3((pTri->v[0].x * scaleX), pTri->v[0].y * scaleY, pTri->v[0].z * scaleZ);
			//pTri->v[0] += glm::vec3(posX, posY, posZ);
			pTri->v[1] = glm::vec3(cube.pVerticesFromFile[cube.pTriangles[i].vertex_index_2].x, cube.pVerticesFromFile[cube.pTriangles[i].vertex_index_2].y, cube.pVerticesFromFile[cube.pTriangles[i].vertex_index_2].z);
			//pTri->v[1] = glm::vec3((pTri->v[1].x * scaleX), pTri->v[1].y * scaleY, pTri->v[1].z * scaleZ);
			//pTri->v[1] += glm::vec3(posX, posY, posZ);
			pTri->v[2] = glm::vec3(cube.pVerticesFromFile[cube.pTriangles[i].vertex_index_3].x, cube.pVerticesFromFile[cube.pTriangles[i].vertex_index_3].y, cube.pVerticesFromFile[cube.pTriangles[i].vertex_index_3].z);
			//pTri->v[2] = glm::vec3((pTri->v[2].x * scaleX), pTri->v[2].y * scaleY, pTri->v[2].z * scaleZ);
			//pTri->v[2] += glm::vec3(posX, posY, posZ);

			glm::vec3 A = pTri->v[1] - pTri->v[0];
			glm::vec3 B = pTri->v[2] - pTri->v[0];

			glm::vec3 sn = glm::cross(A, B);


			//pTri->n = glm::vec3(cube.pVerticesFromFile[cube.pTriangles[i].vertex_index_1].nx, cube.pVerticesFromFile[cube.pTriangles[i].vertex_index_1].ny, cube.pVerticesFromFile[cube.pTriangles[i].vertex_index_1].nz);
			pTri->n = sn;
			pBox->boxTris.push_back(pTri);
		}
		pTerrain->pTheShape = pBox;
		pTerrain->shapeType = cMeshObject::BOX;


		//sTriangle* pTri = new sTriangle();
		//// This is the "phsyics object" for this triangle
		//// This is "model space"
		//pTri->v[0] = glm::vec3(-30.0f, 0.0f, -30.0f);
		//pTri->v[1] = glm::vec3(30.0f, 0.0f, -30.0f);
		//pTri->v[2] = glm::vec3(0.0f, 0.0f, 30.0f);

		//pTerrain->pTheShape = pTri;



		sTextureInfo bricks;
		bricks.name = "brick-wall.bmp";
		bricks.strength = 0.5f;
		pTerrain->vecTextures.push_back( bricks );

		sTextureInfo justin;
		justin.name = "Justin.bmp";
		justin.strength = 0.5f;
		pTerrain->vecTextures.push_back( justin );

		//pTerrain->nonUniformScale = glm::vec3(0.1f,0.1f,0.1f);
		//vec_pObjectsToDraw.push_back( pTerrain );
	}

	{
		cMeshObject* pRaceTrack = new cMeshObject();
		pRaceTrack->position = glm::vec3(0.0f, -10.0f, 0.0f);
		pRaceTrack->setDiffuseColour(glm::vec3(0.0f, 0.0f, 0.0f));
		pRaceTrack->setSpecularPower(100.0f);
		pRaceTrack->bUseVertexColour = false;
		pRaceTrack->meshName = "racetrackv2.ply";		
		//pRaceTrack->meshName = "3d_modelC.ply";		
		pRaceTrack->friendlyName = "The track";
		pRaceTrack->bIsVisible = true;
		pRaceTrack->pDebugRenderer = ::g_pDebugRenderer;
		sTextureInfo bricks;
		bricks.name = "brick-wall.bmp";
		pRaceTrack->vecTextures.push_back(bricks);
		//vec_pObjectsToDraw.push_back(pRaceTrack);
	}

	{
		cMeshObject* pRaceCar= new cMeshObject();
		pRaceCar->position = glm::vec3(0.0f, -9.0f, 0.0f);
		pRaceCar->setDiffuseColour(glm::vec3(0.0f, 0.0f, 0.0f));
		pRaceCar->setSpecularPower(100.0f);
		pRaceCar->bUseVertexColour = false;
		pRaceCar->meshName = "car.ply";
		pRaceCar->friendlyName = "car";
		pRaceCar->bIsVisible = true;
		//sTextureInfo bricks;
		//bricks.name = "brick-wall.bmp";
		//pRaceTrack->vecTextures.push_back(bricks);
		pRaceCar->setMeshOrientationEulerAngles(glm::vec3(90.0f, 0.0f, 0.0f), true);
		
		vec_pObjectsToDraw.push_back(pRaceCar);
		//::g_pObjectToRotate.push_back(pRaceCar);

		::g_pObjectToRotate = new cMeshObject();
		::g_pObjectToRotate->position = glm::vec3(0.0f, -9.0f, 0.0f);
		::g_pObjectToRotate->setDiffuseColour(glm::vec3(0.0f, 0.0f, 0.0f));
		::g_pObjectToRotate->setSpecularPower(100.0f);
		::g_pObjectToRotate->bUseVertexColour = false;
		::g_pObjectToRotate->meshName = "car.ply";
		::g_pObjectToRotate->friendlyName = "car";
		::g_pObjectToRotate->bIsVisible = true;
		//sTextureInfo bricks;
		//bricks.name = "brick-wall.bmp";
		//pRaceTrack->vecTextures.push_back(bricks);
		::g_pObjectToRotate->setMeshOrientationEulerAngles(glm::vec3(90.0f, 0.0f, 0.0f), true);
		
		//vec_pObjectsToDraw.push_back(pRaceCar);
		//vec_pObjectsToDraw.push_back(::g_pObjectToRotate);

		cMeshObject* pCar2 = new cMeshObject();
		pCar2->position = glm::vec3(0.0f, -20.0f, 0.0f);
		pCar2->setDiffuseColour(glm::vec3(1.0f, 0.0f, 0.0f));
		pCar2->setSpecularPower(100.0f);
		pCar2->bUseVertexColour = false;
		pCar2->meshName = "car.ply";
		pCar2->friendlyName = "car2";
		pCar2->bIsVisible = true;
		//sTextureInfo bricks;
		//bricks.name = "brick-wall.bmp";
		//pRaceTrack->vecTextures.push_back(bricks);
		pCar2->setMeshOrientationEulerAngles(glm::vec3(90.0f, 0.0f, 0.0f), true);

		//vec_pObjectsToDraw.push_back(pRaceCar);
		//vec_pObjectsToDraw.push_back(pCar2);
	}

	// Updated physics object
	{	// This sphere is the tiny little debug sphere
		cMeshObject* pPlayerSphere = new cMeshObject();
//		pPlayerSphere->objColour = glm::vec3( 1.0f, 105.0f/255.0f, 180.0f/255.0f );
		pPlayerSphere->setDiffuseColour( glm::vec3( 1.0f, 105.0f/255.0f, 180.0f/255.0f ) );
		pPlayerSphere->friendlyName = "Player";
		float scale = 1.0f;
		pPlayerSphere->nonUniformScale = glm::vec3(scale,scale,scale);
		pPlayerSphere->meshName = "Sphere_320_faces_xyz_n_GARBAGE_uv.ply";			// "Sphere_320_faces_xyz.ply";
		pPlayerSphere->bIsWireFrame = true;

		pPlayerSphere->position = glm::vec3( -100.0f, 10.0f, 0.0f );
		pPlayerSphere->velocity = glm::vec3( 5.0f, 10.0f, 0.0f );		// starts at "up" at 10 mps
		pPlayerSphere->accel = glm::vec3( 0.0f, -5.0f, 0.0f );
		pPlayerSphere->bIsUpdatedByPhysics = true;

		pPlayerSphere->pDebugRenderer = ::g_pDebugRenderer;

		//pTerrain->nonUniformScale = glm::vec3(0.1f,0.1f,0.1f);
		//vec_pObjectsToDraw.push_back( pPlayerSphere );
	}

	{	// This will be our "skybox" object.
		// (could also be a cube, or whatever)
		cMeshObject* pSkyBoxObject = new cMeshObject();
		pSkyBoxObject->setDiffuseColour( glm::vec3( 1.0f, 105.0f/255.0f, 180.0f/255.0f ) );
		pSkyBoxObject->bUseVertexColour = false;
		pSkyBoxObject->friendlyName = "SkyBoxObject";
		float scale = 5000.0f;	
		pSkyBoxObject->nonUniformScale = glm::vec3(scale,scale,scale);
		pSkyBoxObject->meshName = "Sphere_320_faces_xyz_n_GARBAGE_uv_INVERTED_NORMALS.ply";			// "Sphere_320_faces_xyz.ply";
//		pSkyBoxObject->bIsWireFrame = true;

		// Invisible until I need to draw it
		pSkyBoxObject->bIsVisible = false;

		vec_pObjectsToDraw.push_back( pSkyBoxObject );
	}

	const unsigned int NUMBER_OF_BALLS = 0;

	for ( unsigned int count = 0; count != NUMBER_OF_BALLS; count++ )
	// Updated physics object
	{	// This sphere is the tiny little debug sphere
		cMeshObject* pBouncyBall = new cMeshObject();
//		pBouncyBall->objColour = glm::vec3( 1.0f, 105.0f/255.0f, 180.0f/255.0f );
		pBouncyBall->setDiffuseColour( glm::vec3( 1.0f, 105.0f/255.0f, 180.0f/255.0f ) );
		float scale = 5.0f;
		pBouncyBall->nonUniformScale = glm::vec3(scale,scale,scale);
		pBouncyBall->meshName = "Sphere_320_faces_xyz_n_GARBAGE_uv.ply";		// "Sphere_320_faces_xyz.ply";
		pBouncyBall->bIsWireFrame = true;

		pBouncyBall->position = glm::vec3( getRandBetween0and1<float>() * 199.0f - 99.0f, 
		                                   getRandBetween0and1<float>() * 199.0f + 0.5f,
		                                   getRandBetween0and1<float>() * 199.0f - 99.0f);
		pBouncyBall->velocity = glm::vec3( getRandBetween0and1<float>() * 100.0f - 5.0f,
		                                   getRandBetween0and1<float>() * 100.0f - 5.0f, 
		                                   getRandBetween0and1<float>() * 100.0f - 5.0f );	
//
//		pBouncyBall->accel = glm::vec3( 0.0f, -5.0f, 0.0f );
		pBouncyBall->accel = g_ACCEL_GRAVITY;

		pBouncyBall->bIsUpdatedByPhysics = true;

//		pBouncyBall->radius = 5.0f;	// Be careful

		// Set the type
		pBouncyBall->pTheShape = new sSphere(5.0f);
		pBouncyBall->shapeType = cMeshObject::SPHERE;

		pBouncyBall->pDebugRenderer = ::g_pDebugRenderer;


		//pTerrain->nonUniformScale = glm::vec3(0.1f,0.1f,0.1f);
		//vec_pObjectsToDraw.push_back( pBouncyBall );
	}


	// ENDOF: Updated physics object

	{	// This sphere is the tiny little debug sphere
		cMeshObject* pDebugSphere = new cMeshObject();
		pDebugSphere->position = glm::vec3( 0.0f, 0.0f, 0.0f );
//		pDebugSphere->objColour = glm::vec3( 0.0f, 1.0f, 0.0f );
		pDebugSphere->setDiffuseColour( glm::vec3(0.0f, 1.0f, 0.0f) );
		float scale = 0.1f;
		pDebugSphere->friendlyName = "DebugSphere";
		pDebugSphere->nonUniformScale = glm::vec3(scale,scale,scale);
		pDebugSphere->meshName = "Sphere_320_faces_xyz_n_GARBAGE_uv.ply";		// "Sphere_320_faces_xyz.ply";
		pDebugSphere->bIsWireFrame = true;
		pDebugSphere->bIsVisible = false;
		pDebugSphere->pDebugRenderer = ::g_pDebugRenderer;

		//pTerrain->nonUniformScale = glm::vec3(0.1f,0.1f,0.1f);
		//vec_pObjectsToDraw.push_back( pDebugSphere );
	}

	{	// This sphere is the tiny little debug sphere
		cMeshObject* pTriangle = new cMeshObject();
//		pTriangle->objColour = glm::vec3( 0.0f, 1.0f, 1.0f );
		pTriangle->setDiffuseColour( glm::vec3( 0.0f, 1.0f, 1.0f ) );
		pTriangle->friendlyName = "SingleTriangle";
		pTriangle->meshName = "singleTriangle_xyz_n.ply";		// "singleTriangle_xyz.ply";
		pTriangle->bDontLight = true;
		pTriangle->bIsWireFrame = true;

		pTriangle->position = glm::vec3(  -10.0f, 15.0f, 0.0f );
		//pTriangle->preRotation = glm::vec3( 0.0f, 
		//									glm::radians(15.0f), 
		//									glm::radians(75.0f));
		pTriangle->setMeshOrientationEulerAngles( glm::vec3( 0.0f, 15.0f, 75.0f), true );

//		pTriangle->setUniformScale( 1.0f );

		sTriangle* pTri = new sTriangle();
		// This is the "phsyics object" for this triangle
		// This is "model space"
		pTri->v[0] = glm::vec3(-30.0f, 0.0f, -30.0f);
		pTri->v[1] = glm::vec3( 30.0f, 0.0f, -30.0f);
		pTri->v[2] = glm::vec3(  0.0f, 0.0f,  30.0f);

		pTriangle->pTheShape = pTri;
		pTriangle->shapeType = cMeshObject::TRIANGLE;
		
		pTriangle->pDebugRenderer = ::g_pDebugRenderer;

		//pTerrain->nonUniformScale = glm::vec3(0.1f,0.1f,0.1f);
		//vec_pObjectsToDraw.push_back( pTriangle );
	}

	{	// This sphere is the tiny little debug sphere
		cMeshObject* pCubeForBallsToBounceIn = new cMeshObject();
//		pCubeForBallsToBounceIn->objColour = glm::vec3( 0.0f, 1.0f, 0.0f );
		pCubeForBallsToBounceIn->setDiffuseColour( glm::vec3( 0.0f, 1.0f, 0.0f ) );
		pCubeForBallsToBounceIn->bDontLight = true;
		pCubeForBallsToBounceIn->friendlyName = "CubeBallsBounceIn";
		pCubeForBallsToBounceIn->meshName = "cube_flat_shaded_xyz_n_uv.ply";		// "cube_flat_shaded_xyz.ply";
		pCubeForBallsToBounceIn->setUniformScale(100.0f);
		// Cube is 2x2x2, so with a scale of 100x means it's
		//	200x200x200, centred around the origin (0,0,0)
		// The GROUND_PLANE_Y = -3.0f, so place it +97.0 lines up the 'bottom'
		pCubeForBallsToBounceIn->position = glm::vec3(  0.0f, 97.0f, 0.0f );
		pCubeForBallsToBounceIn->bIsWireFrame = true;
				
		pCubeForBallsToBounceIn->pDebugRenderer = ::g_pDebugRenderer;

		//pTerrain->nonUniformScale = glm::vec3(0.1f,0.1f,0.1f);
		//vec_pObjectsToDraw.push_back( pCubeForBallsToBounceIn );
	}

	{	// This sphere is the tiny little debug sphere
		cMeshObject* pPirate = new cMeshObject();
		pPirate->setDiffuseColour( glm::vec3( 1.0f, 1.0f, 1.0f ) );
//		pPirate->setAlphaTransparency( 0.50f );
		pPirate->setAlphaTransparency( 1.0f );
		pPirate->position.x = 25.0f;
		//plighthouse->friendlyName = "Lighthouse";
		//plighthouse->meshName = "Lighthouse_Combined_xyz_n.ply";		// "cube_flat_shaded_xyz.ply";
		//plighthouse->friendlyName = "OldHouse";
		//plighthouse->meshName = "Old_House_Combined_xyz_n.ply";		// "cube_flat_shaded_xyz.ply";
		pPirate->friendlyName = "SkyPirate";
		//pPirate->meshName = "CyclopsFrigate.ply";		// "cube_flat_shaded_xyz.ply";
		pPirate->meshName = "Sky_Pirate_Combined_xyz_n_BlenderSmart_uv.ply";		// "cube_flat_shaded_xyz.ply";
		pPirate->setUniformScale(1.0f);
		pPirate->position = glm::vec3(  10.0f, 0.0f, 0.0f );
//		plighthouse->bIsWireFrame = true;
		//vec_pObjectsToDraw.push_back( pPirate );
	}

	{	// This sphere is the tiny little debug sphere
		cMeshObject* pPirate = new cMeshObject();
		pPirate->setDiffuseColour(glm::vec3(1.0f, 1.0f, 1.0f));
		//		pPirate->setAlphaTransparency( 0.50f );
		pPirate->setAlphaTransparency(1.0f);
		pPirate->position.x = 25.0f;
		pPirate->bIsUpdatedByPhysics = true;
		//plighthouse->friendlyName = "Lighthouse";
		//plighthouse->meshName = "Lighthouse_Combined_xyz_n.ply";		// "cube_flat_shaded_xyz.ply";
		//plighthouse->friendlyName = "OldHouse";
		//plighthouse->meshName = "Old_House_Combined_xyz_n.ply";		// "cube_flat_shaded_xyz.ply";
		pPirate->friendlyName = "PlayerShip";
		pPirate->meshName = "CyclopsFrigate.ply";		// "cube_flat_shaded_xyz.ply";
		//pPirate->meshName = "Sky_Pirate_Combined_xyz_n_BlenderSmart_uv.ply";		// "cube_flat_shaded_xyz.ply";
		float scale = 2.0f;
		pPirate->setUniformScale(scale);
		pPirate->position = glm::vec3(0.0f, 0.0f, 0.0f);
		pPirate->velocity = glm::vec3(0.0f, 0.0f, 0.0f);
		pPirate->objectClass = cMeshObject::objClass::PLAYER;

		pPirate->pTheShape = new sSphere(scale);
		pPirate->shapeType = cMeshObject::SPHERE;

		vec_pObjectsToDraw.push_back(pPirate);
	}

	{
		cMeshObject * ship = findObjectByFriendlyName("PlayerShip");
		//These spheres are for collision detection for the ship
		// This sphere is the tiny little debug sphere
			cMeshObject* pBouncyBall = new cMeshObject();
			//		pBouncyBall->objColour = glm::vec3( 1.0f, 105.0f/255.0f, 180.0f/255.0f );
			pBouncyBall->setDiffuseColour(glm::vec3(1.0f, 105.0f / 255.0f, 180.0f / 255.0f));
			float scale = 5.0f;
			pBouncyBall->nonUniformScale = glm::vec3(scale, scale, scale);
			pBouncyBall->meshName = "Sphere_320_faces_xyz_n_GARBAGE_uv.ply";		// "Sphere_320_faces_xyz.ply";
			pBouncyBall->bIsWireFrame = true;
			pBouncyBall->friendlyName = "ShipSphere";

			pBouncyBall->position = ship->position;
			//pBouncyBall->position.z += 20.0f;
			pBouncyBall->objectClass = cMeshObject::objClass::PLAYERSPHERE;

			pBouncyBall->bIsUpdatedByPhysics = true;
			pBouncyBall->bIsVisible = false;


			//		pBouncyBall->radius = 5.0f;	// Be careful

					// Set the type
			pBouncyBall->pTheShape = new sSphere(scale);
			pBouncyBall->shapeType = cMeshObject::SPHERE;

			pBouncyBall->pDebugRenderer = ::g_pDebugRenderer;


			ship->childObjects.push_back(pBouncyBall);

			//pTerrain->nonUniformScale = glm::vec3(0.1f,0.1f,0.1f);
			vec_pObjectsToDraw.push_back(pBouncyBall);
	}

	{
		cMeshObject * ship = findObjectByFriendlyName("PlayerShip");
		//These spheres are for collision detection for the ship
		// This sphere is the tiny little debug sphere
		cMeshObject* pBouncyBall = new cMeshObject();
		//		pBouncyBall->objColour = glm::vec3( 1.0f, 105.0f/255.0f, 180.0f/255.0f );
		pBouncyBall->setDiffuseColour(glm::vec3(0.0f, 1.0f, 0.0f));
		float scale = 5.6f;
		pBouncyBall->nonUniformScale = glm::vec3(scale, scale, scale);
		pBouncyBall->meshName = "Sphere_320_faces_xyz_n_GARBAGE_uv.ply";		// "Sphere_320_faces_xyz.ply";
		pBouncyBall->bIsWireFrame = true;
		pBouncyBall->friendlyName = "ShipSphere";

		pBouncyBall->position = ship->position;
		pBouncyBall->objectClass = cMeshObject::objClass::PLAYERSPHERE;

		pBouncyBall->bIsUpdatedByPhysics = true;
		pBouncyBall->bIsVisible = false;


		//		pBouncyBall->radius = 5.0f;	// Be careful

				// Set the type
		pBouncyBall->pTheShape = new sSphere(scale);
		pBouncyBall->shapeType = cMeshObject::SPHERE;

		pBouncyBall->pDebugRenderer = ::g_pDebugRenderer;


		ship->childObjects.push_back(pBouncyBall);

		//pTerrain->nonUniformScale = glm::vec3(0.1f,0.1f,0.1f);
		vec_pObjectsToDraw.push_back(pBouncyBall);
	}

	{
		cMeshObject * ship = findObjectByFriendlyName("PlayerShip");
		//These spheres are for collision detection for the ship
		// This sphere is the tiny little debug sphere
		cMeshObject* pBouncyBall = new cMeshObject();
		//		pBouncyBall->objColour = glm::vec3( 1.0f, 105.0f/255.0f, 180.0f/255.0f );
		pBouncyBall->setDiffuseColour(glm::vec3(0.0f, 1.0f, 1.0f));
		float scale = 5.0f;
		pBouncyBall->nonUniformScale = glm::vec3(scale, scale, scale);
		pBouncyBall->meshName = "Sphere_320_faces_xyz_n_GARBAGE_uv.ply";		// "Sphere_320_faces_xyz.ply";
		pBouncyBall->bIsWireFrame = true;
		pBouncyBall->friendlyName = "ShipSphere";

		pBouncyBall->position = ship->position;
		pBouncyBall->objectClass = cMeshObject::objClass::PLAYERSPHERE;

		pBouncyBall->bIsUpdatedByPhysics = true;
		pBouncyBall->bIsVisible = false;


		//		pBouncyBall->radius = 5.0f;	// Be careful

				// Set the type
		pBouncyBall->pTheShape = new sSphere(scale);
		pBouncyBall->shapeType = cMeshObject::SPHERE;

		pBouncyBall->pDebugRenderer = ::g_pDebugRenderer;


		ship->childObjects.push_back(pBouncyBall);

		//pTerrain->nonUniformScale = glm::vec3(0.1f,0.1f,0.1f);
		vec_pObjectsToDraw.push_back(pBouncyBall);
	}

	{
		cMeshObject * ship = findObjectByFriendlyName("PlayerShip");
		//These spheres are for collision detection for the ship
		// This sphere is the tiny little debug sphere
		cMeshObject* pBouncyBall = new cMeshObject();
		//		pBouncyBall->objColour = glm::vec3( 1.0f, 105.0f/255.0f, 180.0f/255.0f );
		pBouncyBall->setDiffuseColour(glm::vec3(1.0f, 0.0f, 0.0f));
		float scale = 5.0f;
		pBouncyBall->nonUniformScale = glm::vec3(scale, scale, scale);
		pBouncyBall->meshName = "Sphere_320_faces_xyz_n_GARBAGE_uv.ply";		// "Sphere_320_faces_xyz.ply";
		pBouncyBall->bIsWireFrame = true;
		pBouncyBall->friendlyName = "ShipSphere";

		pBouncyBall->position = ship->position;
		pBouncyBall->objectClass = cMeshObject::objClass::PLAYERSPHERE;

		pBouncyBall->bIsUpdatedByPhysics = true;
		pBouncyBall->bIsVisible = false;


		//		pBouncyBall->radius = 5.0f;	// Be careful

				// Set the type
		pBouncyBall->pTheShape = new sSphere(scale);
		pBouncyBall->shapeType = cMeshObject::SPHERE;

		pBouncyBall->pDebugRenderer = ::g_pDebugRenderer;


		ship->childObjects.push_back(pBouncyBall);

		//pTerrain->nonUniformScale = glm::vec3(0.1f,0.1f,0.1f);
		vec_pObjectsToDraw.push_back(pBouncyBall);
	}

	{
		cMeshObject * ship = findObjectByFriendlyName("PlayerShip");
		//These spheres are for collision detection for the ship
		// This sphere is the tiny little debug sphere
		cMeshObject* pBouncyBall = new cMeshObject();
		//		pBouncyBall->objColour = glm::vec3( 1.0f, 105.0f/255.0f, 180.0f/255.0f );
		pBouncyBall->setDiffuseColour(glm::vec3(1.0f, 1.0f, 0.0f));
		float scale = 2.0f;
		pBouncyBall->nonUniformScale = glm::vec3(scale, scale, scale);
		pBouncyBall->meshName = "Sphere_320_faces_xyz_n_GARBAGE_uv.ply";		// "Sphere_320_faces_xyz.ply";
		pBouncyBall->bIsWireFrame = true;
		pBouncyBall->friendlyName = "ShipSphere0";

		pBouncyBall->position = ship->position;
		pBouncyBall->objectClass = cMeshObject::objClass::PLAYERBULLET;

		pBouncyBall->bIsUpdatedByPhysics = false;
		pBouncyBall->bIsVisible = false;

		//		pBouncyBall->radius = 5.0f;	// Be careful

				// Set the type
		pBouncyBall->pTheShape = new sSphere(scale);
		pBouncyBall->shapeType = cMeshObject::SPHERE;

		pBouncyBall->pDebugRenderer = ::g_pDebugRenderer;


		//ship->childObjects.push_back(pBouncyBall);

		//pTerrain->nonUniformScale = glm::vec3(0.1f,0.1f,0.1f);
		vec_pObjectsToDraw.push_back(pBouncyBall);
	}

	//******************************
	// Enemy Ship - Seek/Flee
	//******************************
	{
		// Enemy ship type
		cMeshObject* pBouncyBall = new cMeshObject();
		pBouncyBall->setDiffuseColour(glm::vec3(1.0f, 1.0f, 0.0f));
		float scale = 1.0f;
		pBouncyBall->nonUniformScale = glm::vec3(scale, scale, scale);
		pBouncyBall->meshName = "OxossiDestroyer.ply";		// "Sphere_320_faces_xyz.ply";
		pBouncyBall->bIsWireFrame = false;
		pBouncyBall->friendlyName = "EnemyShip0";
		pBouncyBall->position = glm::vec3(60.0f, 0.0f, 50.0f);
		pBouncyBall->velocity = glm::vec3(0.0f, 0.0f, 40.0f);
		pBouncyBall->objectClass = cMeshObject::objClass::ENEMY;

		pBouncyBall->bIsUpdatedByPhysics = true;
		pBouncyBall->bIsVisible = true;

		pBouncyBall->aiType = cMeshObject::aiBehaviour::SEEKFLEE;

		// Set the type
		pBouncyBall->pTheShape = new sSphere(scale);
		pBouncyBall->shapeType = cMeshObject::SPHERE;

		pBouncyBall->pDebugRenderer = ::g_pDebugRenderer;

		vec_pObjectsToDraw.push_back(pBouncyBall);
		aiObjects.push_back(pBouncyBall);
	}

	//******************************
	// Enemy Ship - Pursue/Evade
	//******************************
	{
		// Enemy ship type
		cMeshObject* pBouncyBall = new cMeshObject();
		pBouncyBall->setDiffuseColour(glm::vec3(1.0f, 1.0f, 0.0f));
		float scale = 1.0f;
		pBouncyBall->nonUniformScale = glm::vec3(scale, scale, scale);
		pBouncyBall->meshName = "beacons.ply";		// "Sphere_320_faces_xyz.ply";
		pBouncyBall->bIsWireFrame = false;
		pBouncyBall->friendlyName = "EnemyShip1";
		pBouncyBall->position = glm::vec3(-60.0f, 0.0f, 50.0f);
		pBouncyBall->velocity = glm::vec3(0.0f, 0.0f, 10.0f);
		pBouncyBall->objectClass = cMeshObject::objClass::ENEMY;

		pBouncyBall->bIsUpdatedByPhysics = true;
		pBouncyBall->bIsVisible = true;

		pBouncyBall->aiType = cMeshObject::aiBehaviour::PURSUEEVADE;

		// Set the type
		pBouncyBall->pTheShape = new sSphere(scale * 5.0f);
		pBouncyBall->shapeType = cMeshObject::SPHERE;

		pBouncyBall->pDebugRenderer = ::g_pDebugRenderer;

		vec_pObjectsToDraw.push_back(pBouncyBall);
		aiObjects.push_back(pBouncyBall);
	}

	//******************************
	// Enemy Ship - Approach/Fire
	//******************************
	{
		// Enemy ship type
		cMeshObject* pBouncyBall = new cMeshObject();
		pBouncyBall->setDiffuseColour(glm::vec3(1.0f, 0.0f, 1.0f));
		float scale = 1.0f;
		pBouncyBall->nonUniformScale = glm::vec3(scale, scale, scale);
		pBouncyBall->meshName = "HeliosFrigate2.ply";		// "Sphere_320_faces_xyz.ply";
		pBouncyBall->bIsWireFrame = false;
		pBouncyBall->friendlyName = "EnemyShip2";
		pBouncyBall->position = glm::vec3(-60.0f, 0.0f, -60.0f);
		pBouncyBall->velocity = glm::vec3(0.0f, 0.0f, 10.0f);
		pBouncyBall->objectClass = cMeshObject::objClass::ENEMY;

		pBouncyBall->bIsUpdatedByPhysics = true;
		pBouncyBall->bIsVisible = true;

		pBouncyBall->aiType = cMeshObject::aiBehaviour::APPROACHFIRE;

		// Set the type
		pBouncyBall->pTheShape = new sSphere(scale * 5.0f);
		pBouncyBall->shapeType = cMeshObject::SPHERE;

		pBouncyBall->pDebugRenderer = ::g_pDebugRenderer;

		vec_pObjectsToDraw.push_back(pBouncyBall);
		aiObjects.push_back(pBouncyBall);
	}

	//********************
	// Enemy Bullet
	//********************
	{
		cMeshObject * ship = findObjectByFriendlyName("EnemyShip2");
		//These spheres are for collision detection for the ship
		// This sphere is the tiny little debug sphere
		cMeshObject* pBouncyBall = new cMeshObject();
		//		pBouncyBall->objColour = glm::vec3( 1.0f, 105.0f/255.0f, 180.0f/255.0f );
		pBouncyBall->setDiffuseColour(glm::vec3(1.0f, 0.0f, 1.0f));
		float scale = 2.0f;
		pBouncyBall->nonUniformScale = glm::vec3(scale, scale, scale);
		pBouncyBall->meshName = "Sphere_320_faces_xyz_n_GARBAGE_uv.ply";		// "Sphere_320_faces_xyz.ply";
		pBouncyBall->bIsWireFrame = true;
		pBouncyBall->friendlyName = "EnemySphere0";

		pBouncyBall->position = ship->position;
		pBouncyBall->objectClass = cMeshObject::objClass::ENEMYBULLET;

		pBouncyBall->bIsUpdatedByPhysics = false;
		pBouncyBall->bIsVisible = false;

		// Set the type
		pBouncyBall->pTheShape = new sSphere(scale);
		pBouncyBall->shapeType = cMeshObject::SPHERE;

		pBouncyBall->pDebugRenderer = ::g_pDebugRenderer;


		ship->childObjects.push_back(pBouncyBall);

		//pTerrain->nonUniformScale = glm::vec3(0.1f,0.1f,0.1f);
		vec_pObjectsToDraw.push_back(pBouncyBall);
	}

	//******************************
	// Enemy Ship - Wander/Idle
	//******************************
	{
		// Enemy ship type
		cMeshObject* pBouncyBall = new cMeshObject();
		pBouncyBall->setDiffuseColour(glm::vec3(1.0f, 0.0f, 1.0f));
		float scale = 0.1f;
		pBouncyBall->nonUniformScale = glm::vec3(scale, scale, scale);
		pBouncyBall->meshName = "AsteroidStation.ply";		// "Sphere_320_faces_xyz.ply";
		pBouncyBall->bIsWireFrame = false;
		pBouncyBall->friendlyName = "EnemyShip3";
		pBouncyBall->position = glm::vec3(60.0f, 0.0f, -60.0f);
		pBouncyBall->velocity = glm::vec3(0.0f, 0.0f, 10.0f);
		pBouncyBall->objectClass = cMeshObject::objClass::ENEMY;

		pBouncyBall->bIsUpdatedByPhysics = true;
		pBouncyBall->bIsVisible = true;

		pBouncyBall->aiType = cMeshObject::aiBehaviour::WANDERIDLE;

		// Set the type
		pBouncyBall->pTheShape = new sSphere(5.0f);
		pBouncyBall->shapeType = cMeshObject::SPHERE;

		pBouncyBall->pDebugRenderer = ::g_pDebugRenderer;

		//int randX = std::rand() % 1024;
		int winH = std::rand() % windowHeight * 0.6f;
		int winW = std::rand() % windowWidth * 0.6f;
		int randX = std::rand() % ((winW * 2) - 0 + 1);
		randX -= (winW / 2);
		int randY = 0;
		int randZ = std::rand() % ((winH * 2) - 0 + 1);
		randZ -= (winH / 2);

		pBouncyBall->targetPos = glm::vec3(randX, randY, randZ);
		glm::vec3 dir = glm::normalize(pBouncyBall->targetPos - pBouncyBall->position);
		pBouncyBall->velocity = dir * 5.0f;

		std::cout << "Tx: " << pBouncyBall->targetPos.x << ", " << "Ty: " << pBouncyBall->targetPos.y << ", " << "Tz: " << pBouncyBall->targetPos.z << ", " << std::endl;

		vec_pObjectsToDraw.push_back(pBouncyBall);
		aiObjects.push_back(pBouncyBall);
	}

	return;
}