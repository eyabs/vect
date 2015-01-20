/*
Eric Yablunosky

vect.h
mathematical vector object file
*/

#include <iostream>
#include <cmath>
#include <cstdlib>

//using namespace std;

class Vect{
  private:
    int iNumDims;
    double *iComponents = NULL;
    //setters
    void setNumDims( int aNumDims ) { iNumDims = aNumDims; }
    void setComponent( int, double );
    void setComponents( double *);
    Vect& copyAssign(const Vect& aV2);

  public:
    
    //constructors
    Vect(); //default, 2d 0-Vector
    Vect(int aNumDims); //0-vector with aNumDims dimensions
    Vect(int, double *); //input vector manually
    
    
    //getters
    int numDims() const { return iNumDims; }
    double * cmps() const { return iComponents; } //array w/ all components
    double cmp( int aDim ) const; //single component
    
    //public member functions and operator overloads
    void print();
    double mag();
    double magSq();
    Vect add( const Vect& aVect2 ) const;
    Vect& addOn( const Vect& aVect2 );
    double dot( const Vect& v2) const;		       // Dot Product.
    Vect times(const double aK) const;		   // Scalar Multiplication like Vect * double.
    Vect divide(const double aK) const;        // Scalar Division.
    
    Vect& operator= (const Vect& aVect2) { return this->copyAssign(aVect2); }
    Vect operator+ ( const Vect& aVect2 ) const { return this->add(aVect2); }
    Vect& operator+= ( const Vect& aVect2 ) { return this->addOn(aVect2); }
    Vect operator* (const double aK) const { return this->times(aK); }
    Vect operator/ (const double aK) const { return this->divide(aK); }
    double& operator[](std::size_t dim) { return (this)->iComponents[dim]; }
    const double& operator[](std::size_t dim) const { return const_cast<Vect&> (*this)[dim]; }
    //Vect& operator*= 

    // Scalar Multiplication/Division in form (double) * Vect
    friend Vect operator* (const double aK, const Vect& aV){
    	return aV.times(aK);
    }
    // Dot Product
    friend double operator* (const Vect& aVect1, const Vect& aVect2) { 
        return aVect1.dot(aVect2); 
    }
    friend std::ostream& operator<<(std::ostream& out, const Vect& aV){
		out << "< ";
		for( int dim = 0; dim < aV.numDims(); dim++ ){
			out << aV[dim];
			if( dim != ( aV.numDims() - 1) )
		 		out << ", ";
	    }
		out << " >";
		return out;
	}

    //Destructor
    ~Vect();

};



