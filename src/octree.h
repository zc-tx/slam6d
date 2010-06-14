/**
 * @file 
 * @brief Representation of an octree
 * @author Kai Lingemann. Institute of Computer Science, University of Osnabrueck, Germany.
 * @author Andreas Nuechter. Institute of Computer Science, University of Osnabrueck, Germany.
 */

#ifndef OCTREE_H
#define OCTREE_H

#include <vector>
using std::vector;
#include <list>
using std::list;
#include <set>
using std::set;

/**
 * @brief Octree
 * 
 * A cubic bounding box is calculated
 * from the given 3D points. Then it
 * is recusivly subdivided into smaller
 * subboxes
 */
class OctTree {

public:
  
  OctTree(double **pts, int n, double _voxelSize);
  OctTree(list<double*> &splitPoints, double center[3], 
		double x_size, double y_size, double z_size);
  virtual ~OctTree();
  
  void GetOctTreeCenter(vector<double*>&c);
  void GetOctTreeRandom(vector<double*>&c);
  void GetOctTreeRandom(vector<double*>&c, unsigned int ptspervoxel);
 
protected:
  
  /*
  int countPoints(double **pts, int n, double center[3], 
			   double x_size, double y_size, double z_size);
  */
  
  virtual void countPointsAndQueue(list<double*> &i_points,
							double center[8][3], 
							double x_size, double y_size, double z_size,
							OctTree **child);
  
  virtual void countPointsAndQueue(double **pts, int n,
							double center[8][3], 
							double x_size, double y_size, double z_size,
							OctTree **child);
  

  /**
   * the (maximal 8) children of a box
   */
  OctTree **child;

  /**
   * storing the points
   */
  list<double*> points;
  
  /**
   * storing the center
   */
  double center[3];
  
  /**
   * storing the dimensions
   */
  double x_size, y_size, z_size;
  
  /**
   * is it a leaf?
   */
  bool leaf;

  /**
   * storing the voxel size
   */
  static double voxelSize;
};

#endif