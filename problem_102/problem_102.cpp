/*
 * Problem 102 from projectEuler.net
 *
 * Three distinct points are plotted at random on a Cartesian plane, for which
 * -1000 ≤ x, y ≤ 1000, such that a triangle is formed.
 *
 * Consider the following two triangles:
 *
 *       A(-340,495), B(-153,-910), C(835,-947)
 *       X(-175,41), Y(-421,-714),  Z(574,-645)
 *
 * It can be verified that triangle ABC contains the origin, whereas triangle
 * XYZ does not.
 *
 * Using triangles.txt (right click and 'Save Link/Target As...'), a 27K text
 * file containing the co-ordinates of one thousand "random" triangles, find the
 * number of triangles for which the interior contains the origin.
 *
 * NOTE: The first two examples in the file represent the triangles in the
 * example given above.
 */

/*
 * The area of the triangle ABC is found and then the area of each of the
 * triangles formed by AB0, A0C, 0BC.  If 0 is on the boundary or inside of ABC,
 * then the sum of the sub-trianlges should equal the area of ABC.  The area is
 * found by taking one half the absolute value of the cross product of two sides
 * of the triangle.
 */
/*
 * The solution is 228
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include "../libsrc/projectEuler_math.h"

using namespace std;

/*
 * Function Declarations
 */
void showTri(
        const float *a, const float *b, const float *c,
        const float *d, const bool   isInside );

// Constants
const float origin[2] = {0, 0};

/*
 * Main
 */
int main( int argc, char **argv ) {
    projectEuler_math pe_math;
    float    a[2]       = {0};
    float    b[2]       = {0};
    float    c[2]       = {0};
    float    area       = 0;
    float    subArea    = 0;
    bool     isInside   = false;
    char     fileName[] = "../resources/problem_102.triangles.txt";
    int      count      = 0;
    ifstream fin;

    fin.open( fileName );

    if ( fin.is_open() ) {
        cout << fileName << " is open" << endl;
    }

    while ( !fin.eof() ) {
        fin >> a[0]; fin.get();
        fin >> a[1]; fin.get();
        fin >> b[0]; fin.get();
        fin >> b[1]; fin.get();
        fin >> c[0]; fin.get();
        fin >> c[1]; fin.get();

        area = pe_math.areaTri( a, b, c );

        subArea =
            pe_math.areaTri( a,      b, origin ) +
            pe_math.areaTri( a,         origin, c ) +
            pe_math.areaTri( origin, b, c );

        if ( area < subArea )
        {
            isInside = false;
        } else
        {
            isInside = true;
            count++;
        }

        // showTri( a, b, c, origin, isInside );
    } // end of reading from file

    fin.close();

    cout << endl;

    cout << "There are " << count << " triangles containing the origin" << endl;

    return 0;
} // end Main


/*
 * Function Definitions
 */
void showTri( const float *a, const float *b, const float *c, const float *d, const bool isInside ) {
    cout << "Triangle "
        << "A[" << setw( 4 ) << a[0] << " " << setw( 4 ) << a[1] << "], "
        << "B[" << setw( 4 ) << b[0] << " " << setw( 4 ) << b[1] << "], "
        << "C[" << setw( 4 ) << c[0] << " " << setw( 4 ) << c[1] << "] ";

    if ( isInside )
    {
        cout << "contains ";
    } else
    {
        cout << "does not contain ";
    }

    cout << "the point [" << d[0] << " " << d[1] << "]";

    cout << endl;
}
