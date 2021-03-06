#ifndef INCLUDES_H
#define INCLUDES_H
#include "GL/freeglut.h"
#include "GL/gl.h"
#include <X11/Xlib.h>
#include <png.h>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <list>
#include <vector>
#include <set>
#include <map>
#include <tuple>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <random>
#include <chrono>
#include <stdio.h>
#include <sstream>

using namespace std;

#define VISUALIZATION	1
// Learning Switch
#define LEARNING 		1

// Data Collection
#define COLLECT_DATA 	0
#define AUTOSAVE 		1 // For training, save weights to file when num_epocs reached
#define AUTOLOAD		0 // For evaluation of a trained network, start with loaded weights
#define AUTO_EXIT		1 // Automatically exit program after num_epocs

// I/O Parameters
#define EXP_FOLDER 	 	"June6eatenhigher/" // Optional - Folder to store results
#define WEIGHTS_FILE	"" // Leave these as empty strings for automatic assignment
#define DISTANCE_FILE	""
#define COUNT_FILE		""

// MLP Parameters
#define MLP_I			6//((NUM_OBSTACLES == 0) ? 4 : 6) // Number of inputs
#define MLP_J			5 // Number of HL units
#define MLP_K			2 // Number of outputs
#define MLP_INIT_RANGES	1.0

// Simulation Parameters
#define TIME_SCALE 		5
#define EPOCH_STEPS		(5000/TIME_SCALE)

// Reward Function			// Choose one
#define CLASSIC_REW		1 	// Distance to goal weighted by time
#define ALTERNATE_REW	0 	// Minimum Dist - Reaching the goal is rewarded, not staying there

// Evolution Parameters
#define POP_SIZE		15
#define NUM_PARENTS		5
#define NUM_EPOCHS		1
#define MUTATION_RANGE	0.1 // Set to zero when testing

// Sim Parameters
#define NUM_LEADERS		5 //16
#define NUM_ROBOTS		10 //40
#define NUM_GOALS		1
#define GOAL_RADIUS_SQ  20000 // need to determine whether this is reasonable?
#define NUM_OBSTACLES	0
#define ROBOT_SPAWN_RNG	50
#define GOAL_SPAWN_RNG	500
#define ROBOT_VEL		(1.00*TIME_SCALE)
#define LEADER_VEL		(1.00*TIME_SCALE)
#define ROBOT_STEERING 	(0.05*TIME_SCALE)
#define DEFAULT_TOL		0.05
#define PI				3.14159265
#define BOUNDED_WORLD 	1
#define WORLD_SIZE_X	750 //500
#define WORLD_SIZE_Y	750 //500
#define COMM_MODEL 		'M'
#define N_TOP 			6
//avoid
#define NUM_ADVERSARIES 3
#define ADV_VEL			(0.05*TIME_SCALE)
#define ADV_STEERING 	(0.005*TIME_SCALE)

// Flock Parameters
#define REP_RADIUS 		400		// 20
#define ORI_RADIUS 		900		// 30
#define ATR_RADIUS 		2500	// 50			
#define VIS_ANGLE		(2*PI/3)
#define SWARM_PULL		0.00 // amount of influence agents have on leaders on [0, 1] scale

// File Parameters
#define BUFFER_SIZE		256

// Video Parameters
#define WINDOW_TITLE	"Video"
#define FULL_SCREEN		0
#define SIM_STEP_TIME	0.0000001

// Light trail for the lulz
#define ENABLE_TRAIL 	0
#define SWARM_TRAIL 	0
#define TRAIL_LENGTH	100.0

// Debugging Tools
#define VISUALIZE_RADII	1

// Camera Parameters
#define CAM_SPEED		10
#define SCN_SCALE		2.00

// Keyboard Commands
#define EXIT			27
#define KEY_UP			'w'
#define KEY_DOWN		's'
#define KEY_LEFT		'a'
#define KEY_RIGHT		'd'
#define KEY_ZOON_IN		'e'
#define KEY_ZOON_OUT	'q'
#define SIM_SPEED_UP	'o'
#define SIM_SLOW_DOWN	'p'
#define RESET_ZOOM		'z'
#define RESET_VIEW_POS	'h'
#define LOCK_VIEW_ROBOT	'l'
#define SAVE_WEIGHTS	'c'
#define LOAD_WEIGHTS	'v'

// Mathematical Operations
void angle_wrap(double &input);
double deg_to_rad(double input);
double rad_to_deg(double input);
double map_range(double val, double min1, double max1, double min2, double max2);
double clamp_val(double val, double min, double max);
// Random number generation
double gen_rand_range(double begin_range, double end_range);

#endif
