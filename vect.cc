/*
vect.cc

mathematical vector member function definiton file

Eric Yablunosky
*/

#include "vect.h"

/**Vect()
 **Delfault Constructor
 **Initializes the vector to a 2d vector: (0,0)
 **/
Vect::Vect(){
    setNumDims(2);
    //iComponents = NULL;
 //    iComponents = new double[ numDims() ];
 //    iComponents[0] = double (0.0);
	// iComponents[1] = double (0.0);    
    //delete [] components;
}

/**Vect( int aNumDims )
 **Constructor
 **Initializes the constructor to a vector with aNumDim components 
 **/
Vect::Vect( int aNumDims ){
    iNumDims = aNumDims;
    //iComponents = NULL;
    //for( int dim = 0; dim < aNumDims; dim++ )
    //   newComponents[dim] = 0.0;
    //delete [] iComponents
 
}

/**Vect( int aNumDims, double * components )
 **Constructor
 **Initializes the constructor to the given components
 **/
Vect::Vect( int aNumDims, double * aComponents ){
    iNumDims = aNumDims;

    iComponents = new double[aNumDims];
    for (int dim = 0; dim < aNumDims; dim++)
    	iComponents[dim] = aComponents[dim];
    //setComponents( aComponents );
}

/**setComponents( double * aComponents ){
 **Pub. Member Function, manually sets or changes components
 **/
void Vect::setComponents( double * aComponents ){
    int nDims = this->iNumDims;
    double * newComponents = new double[nDims];

    for( int dim = 0; dim < nDims; dim++ )
	    newComponents[dim] = aComponents[dim];
	delete [] iComponents;
	iComponents = newComponents;
}

/**setComponent( int aDim, double aComponent )
 **Pub. Member Function, manually sets or changes component
 **/
void Vect::setComponent( int aDim, double aComponent ){
    iComponents[aDim] = aComponent;
}

/** copyAssign( const Vect& aV2 )
 ** Copies values of Vect aV2 to this Vect.
 **/
Vect& Vect::copyAssign( const Vect& aV2 ){
	if (this != &aV2){
		// delete allocated memory;
		delete [] iComponents;

		// Reset iNumDims if not equal
		if (this->iNumDims != aV2.numDims()){
			this->iNumDims = aV2.numDims();
		}

		// Copy numdims and realocate / copy componets.
		int nDims = this->iNumDims;

	    double * iComponents = new double[nDims];
	    for( int dim = 0; dim < nDims; dim++ )
		    iComponents[dim] = aV2.cmps()[dim];
	}

	return *this;
}

/**cmp( int aDim )
 **Pub. Member Function, returns the aDim-th component (or 0 if out of range)
 **/
double Vect::cmp ( int aDim ) const { 
	double component = 0.0;	
	if( aDim < numDims() )   
	   	component = iComponents[aDim]; 
	else
		component = 0.0;   
		
	return component;
}

/** double Vect::mag()
 ** Returns the magnitude of the vector: square root of sum of squares of components
 **/
double Vect::mag(){
    double mag = 0.0;
    for( int dim = 0; dim < numDims(); dim++ )  
	   mag += ((*this)[dim]) * ((*this)[dim]);
    return sqrt(mag);
}

/** double Vect::magSq()
 ** Returns the square of the magnitude: sum of squares of components
 **/
double Vect::magSq(){
    double mag = 0.0;
    for( int dim = 0; dim < numDims(); dim++ )  
	   mag += ((*this)[dim]) * ((*this)[dim]);
    return mag;
}

/** double Vect::dot(Vect v2)
 ** Returns the dot product of two vectors
 **/
double Vect::dot(const Vect& v2) const{
	double dotProd = 0.0;
	int dim = 0;
	// Sum products of corresponding components
	while(dim < this->iNumDims && dim < v2.iNumDims)
	{
		dotProd += this->cmp(dim) * v2.cmp(dim);
		dim++;
	}
	return dotProd;
}

/**	void Vect::times( aK )
 ** Scalar multiplication of a vector...\
 ** each component gets multiplied by aK
 **/
Vect Vect::times(const double aK) const{
	int nDims = this->numDims();
	double * newComponents = new double[nDims];
	for( int dim = 0; dim < nDims; dim++ ){
	  	 newComponents[dim] = (iComponents[dim] * aK); 
 	}
 	Vect newVect(nDims, newComponents);
 	return newVect;
}

/**	void Vect::divide( aK )
 ** Scalar division of a vector...\
 ** each component gets divided by aK
 **/
Vect Vect::divide(const double aK) const{
	int nDims = this->numDims();
	double * newComponents = new double[nDims];

	// Copy new componet values to allocated memory
	for( int dim = 0; dim < nDims; dim++ ){
	  	 newComponents[dim] = iComponents[dim] / aK; 
 	}
 	//Declare new vect object
 	Vect newVect(nDims, newComponents);
 	return newVect;
}
	
/**	void Vect::print()
 ** Prints a vector like so: < 1, 2, 3 >
 **/
void Vect::print(){
	 std::cout << "< ";
	 for( int dim = 0; dim < numDims(); dim++ ){
	 	  std::cout << iComponents[dim];
	 	  if( dim != ( numDims() - 1) )
	 	  	  std::cout << ", ";
     }
	 std::cout << " >";			   
}


/** Vect::add( Vect aVect2 )
 ** Adds two vectors, returning a vector with the larger number 
 ** of components between the two Vect objects.
 **/
Vect Vect::add( const Vect& aVect2 )const {	

	// Case for two vectors with the same number of components.
	if (this->iNumDims == aVect2.numDims()){
		int nDims = this->iNumDims;	
	    double * newComponents = new double[nDims];
	    for( int dim = 0; dim < nDims; dim++ ){
		  	 newComponents[dim] = this->cmp(dim) + aVect2.cmp(dim) ; 
	 	} 
	 	Vect newVect(nDims, newComponents);
    	return ( newVect ); 
	}
	// Case for two vectors of different number of componets.
	else{
		// Assign big and small pointers to the respoective vectors.
		const Vect *bigV = NULL;
		const Vect *smallV = NULL;
		if (this->iNumDims >= aVect2.numDims()){
			bigV = this;
			smallV = &aVect2;
		}
		else{
			bigV = &aVect2;
			smallV = this;
		}
		
		// Storing the number of dims for each vect.
		int bigger = bigV->numDims();
		int smaller = smallV->numDims();
		double * newComponents = new double[bigger];

		// Assign the new components.
		for (int dim = 0; dim < bigger; dim++){
			if(dim < smaller){
				newComponents[dim] = bigV->cmp(dim) + smallV->cmp(dim) ; 
			}
			else{
				newComponents[dim] = bigV->cmp(dim); 
			}
		}

		// Create and return new vector.
		Vect newVect(bigger, newComponents);
		return newVect;
	}
    
}


Vect& Vect::addOn( const Vect& aVect2 ){
	
	// Case for two vectors with the same number of components.
	if (this->iNumDims == aVect2.numDims()){
		int nDims = this->iNumDims;	
	    double * newComponents = new double[nDims];
	    for( int dim = 0; dim < nDims; dim++ ){
		  	 newComponents[dim] = this->cmp(dim) + aVect2.cmp(dim) ; 
	 	} 
	 	delete [] iComponents;
	 	iComponents = newComponents;
    	return (*this); 

	}
	// Case for two vectors of different number of componets.
	else{
		// Assign big and small pointers to the respoective vectors.
		const Vect *bigV = NULL;
		const Vect *smallV = NULL;
		if (this->iNumDims >= aVect2.numDims()){
			bigV = this;
			smallV = &aVect2;
		}
		else{
			bigV = &aVect2;
			smallV = this;
		}
		
		// Storing the number of dims for each vect.
		int bigger = bigV->numDims();
		int smaller = smallV->numDims();
		double * newComponents = new double[bigger];

		// Assign the new components.
		for (int dim = 0; dim < bigger; dim++){
			if(dim < smaller){
				newComponents[dim] = bigV->cmp(dim) + smallV->cmp(dim) ; 
			}
			else{
				newComponents[dim] = bigV->cmp(dim); 
			}
		}
		iNumDims = bigger;
		delete [] iComponents;
		iComponents = newComponents;
		return (*this);
	}
}


/**~Vect()
 **Destructor. frees dynamically allocated memory.
 **/
Vect::~Vect(){	 }
