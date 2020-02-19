#include "Median.h"


//Public Functions
	/**********************************************************************
	insert()
	Parameters: one int
	Complexity: O(log(n))

	Calls the insertAux function and passes it the number to be inserted.
	The complexity is O(log(n)) because in the worst case scenario, the push
	and pop methods are being called for a priority queue. Both of those
	methods are O(log(n)).
	***********************************************************************/
void Median::insert(int num) {
	insertAux(num);
}
	
	/**********************************************************************
	extractMedian()
	Parameters: none
	Complexity: O(log(n))

	Calls the extractMedianAux function.
	The complexity is O(log(n)) because in the worst case scenario, the
	pop method is being called for a priority queue. Pop is O(log(n)).
	***********************************************************************/
void Median::extractMedian() {
	extractMedianAux();
}

//Private Functions
	/**********************************************************************
	insertAux()
	Parameters: one int
	Complexity: O(log(n))

	This function takes an integer and assigns it either as the median or
	pushes it to a priority queue. It makes sure that both of the priority 
	queue sizes are acceptable. If not, it rebalances them. 

	The complexity is O(log(n)) because in the worst case scenario, the push
	and pop methods are being called for a priority queue. Both of those
	methods are O(log(n)).
	***********************************************************************/
void Median::insertAux(int num){
	// See if the median already has a valid value. If not, the number to 
	// be inserted is assigned to the median variable.
	if (medVal == false) {
		med = num;
		medVal = true;
	}
	
	else {
		if (num < med) {	// compare number to median
			lessQ.push(num);// push to lessQ
			lSize++;		// increment size of lessQ
		}
		else {				
			greaterQ.push(num);// push to greaterQ
			gSize++;			// increment size variable of greaterQ
		}

		// Make sure the sizes of both priority queues are acceptable.
		// GreaterQ should be equal to the size of lessQ or at most one element
		// larger.
		if (lSize > gSize) {
			greaterQ.push(med); 
			gSize++;
			med = lessQ.top();	// assign the top of lessQ to the median
			lessQ.pop();
			lSize--;
		}
		else if ( gSize > lSize +1) {
			lessQ.push(med);
			lSize++;
			med = greaterQ.top();  // assign the top of greaterQ to the median
			greaterQ.pop();
			gSize--;
		}
	}
}

	/**********************************************************************
	extractAux()
	Parameters: none
	Complexity: O(log(n))

	This function prints the current median and replaces it with the top of 
	one of the priority queues, depending on their sizes.

	The complexity is O(log(n)) because in the worst case scenario, the
	pop method is being called for a priority queue. Pop is O(log(n)).
	***********************************************************************/
void Median::extractMedianAux() {

	if (medVal == false)	//Check to see if median has valid data.
		return;

	cout << med << '\n';	//Print the median	
	
	if (lSize == 0 && gSize == 0) { // If the Qs are empty and the median
		medVal = false;				// has already been printed, there is 
		cout << "No more numbers to extract." << endl;  // no valid median.
		return;
	}

	if (lSize == gSize) {	// If the sizes of the 2 Qs are the same, 
		med = lessQ.top();  // then the new median is taken from the top of
		lessQ.pop();		// lessQ
		lSize--;
	}

	else if (gSize > lSize) {	// If greaterQ is larger than lessQ, the new
		med = greaterQ.top();	// median is taken from the top of greaterQ.
		greaterQ.pop();
		gSize--;
	}
}

