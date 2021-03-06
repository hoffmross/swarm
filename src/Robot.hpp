#ifndef ROBOT_H
#define ROBOT_H
#include "includes.hpp"
#include "Wired.hpp"
#include "mlp.hpp"
#include "Textured.hpp"

/*
Robot representation.
*/

class Robot: public Wired{

	private:
		double v; // Absolute linear velocity
		double a; // Absolute angular velocity

		// Goal Target Position
		pair<double,double> goal;
		pair<double,double> neighbor_centroid;

		// Reynold's Radii
		double radius_rep;
		double radius_ori;
		double radius_att;

		// Vector of all robots in the swarm
		vector<Robot> *flock;
		
		// Neighbor Sets
		set<Robot*> neighbor_rep;
		set<Robot*> neighbor_ori;
		set<Robot*> neighbor_att;

	public:

		Mlp *mlp;

		bool selected; // User selected (my mouse selection)
		bool leader;
		//avoid
		bool adversary;

		double acc_dist;
		//avoid
		vector<Robot> *adversaries;
		bool eaten;
		vector<pair<double, double>> prevCoords;
		char comm_model;
		int goal_group;
		Robot(
				double x,
				double y,
				double w,
				double h,
				double r,
				double v,
				double s,
				vector<pair<double, double>> shape,
				vector<Robot> *flock,
				//vector<Robot> *adversaries,
				double radius_rep,
				double radius_ori,
				double radius_att,
				bool leader,
				int goal_group
			);
		virtual ~Robot();
		void respawn(double x,double y,double t,Mlp *mlp);
		void set_goal_target_pos(double gx,double gy);
		bool is_within_goal_radius(vector<Textured> &goals);
		//avoid
		void adv_update();
		void update(double weight, vector<Textured> &goals, vector<Textured> &obstacles);
		void update_neighbors();
		set<Robot*> get_neighbors_M(double radiusMax, double radiusMin = 0.0);
		set<Robot*> get_neighbors_V(double radiusMax, double radiusMin = 0.0);
		set<Robot*> get_k_nearest(set<Robot*>, int);
		double swarm();
		pair<double,double> compute_force(set<Robot*> &neighbors);
		pair<double,double> compute_centroid(set<Robot*> &neighbors, pair<double,double> prev);
		pair<double,double> leader_reasoning(vector<Textured> &obstacles);
		double reynolds_rules();
		double wall_repulsion(double xlim, double ylim);
		void update_trail();
		// Distances
		double angle_to_point(pair<double,double> &input);
		double angle_to_point(double x, double y);
		double distance_to_point(pair<double,double> &input);
		double distance_to_point(double x, double y);
		double distance_to_robot(Robot *robot);
		//avoid
		pair<double, double> nearest_adv_dist_angle();
		double sq_distance_to_point(pair<double,double> &input);
		double sq_distance_to_point(double x, double y);
		double sq_distance_to_robot(Robot *robot);
		double sq_distance_to_closest_object(vector<Textured> &goals);
		Textured* closest_object(vector<Textured> &objects);

		bool check_col();
		bool check_col(vector<Textured> &obstacles, float dx, float dy);
		void render_robot();
};

#endif
