/*    @file IntVec.cpp   
      @author Matt Hoendorf <hoendomd@mail.uc.edu>
      @date 09-16-2014

			@description Implements vector-like container for integers.
*/

#include <string>
#include "IntVec.h"
#include "math.h"
#include <iostream>

const int initCap = 1;

//Default 
IntVec::IntVec(){
  data_cap = initCap;
  data_size = 0;
  data = new int[data_cap];  
}

//Constructor - takes data in list form : [ v1, v2, ... vn ]
IntVec::IntVec(const string& values){
  data_cap = initCap;
  data_size = 0;
  int space = 0;
  int temp = 0;
  data = new int[data_cap];
  unsigned long length = values.size();
  for(unsigned int i = 0; i < length; i++){
    if(values[i] >= '0' && values[i] <= '9'){ // If char is # 0-9
      if(data_size == data_cap){ // Check for potential overflow (size>capacity)
        addCap();
      }
      temp = values[i]-48; // Set temp int to #
      while(values[i+1] >= '0' && values[i+1] <= '9' && i!=length-1){
        temp = (temp*10)+(values[i+1]-48); // Check if following char is also a
        i++;                               // number to store numbers > 9. 
      }                                    // (e.g. "12" = [12], not [1][2]).
      data[space] = temp;
      data_size++;
      space++; // Array loc increment.
      i++; // String char increment.
    }
    else if(values[i]!=' '&&values[i]!=','&&values[i]!='['&&values[i]!=']'){
      if(data_size == data_cap){ // Check for potential overflow (size>capacity)
        addCap();
      }
      data[space] = 0;
      data_size++;
      space++;
      i++;
    } 
  }
}

//Copy Constructor
IntVec::IntVec(const IntVec& other){
  data_size = 0;
  data_cap = other.data_cap;
  data = new int[data_cap];
  for (unsigned int i = 0; i < other.data_size; i++){ // Copy all data values 
    data[i] = other.data[i];                          // to new IntVec.
    data_size++;
  } 
}

//Destructor
IntVec::~IntVec(){
  delete[] data;
}

//Pushes new data to front of array
void IntVec::push_back(int value){
  if(data_size == data_cap){ // Check for potential overflow (size>capacity)
    addCap();
  }
  data[data_size] = value; // Push value to the end of the array
  data_size++;
}

//Returns data value at specific location
int IntVec::getAt(int loc){
  return data[loc];
}

//Sets data value at specific location
bool IntVec::setAt(int value, int loc){
  data[loc] = value;
  if(data[loc] == value){ // Check if successful, return 1 if so.
    return 1;
  }
  return 0;
}

//Returns size of data array
unsigned int IntVec::size(){
  return data_size;
}

//Returns capacity of data array
unsigned int IntVec::capacity(){
  return data_cap;
}

//Clears the data array (starts from scratch)
void IntVec::clear(){
  delete[] data;
  data_cap = initCap;
  data_size = 0;
  data = new int[data_cap];
}  

// Returns sum of current IntVec's values
long IntVec::sum(){
  unsigned long sum = 0; 
  for(unsigned int i = 0; i < data_size; i++){
    sum+=data[i]; // Sum of values
  }
  return sum;
}

// Returns avg of current IntVec's values
float IntVec::average(){
  unsigned long sum = 0; 
  for(unsigned int i = 0; i < data_size; i++){
    sum+=data[i];
  }
  if(data_size==0){
    return 0;
  }
  return (float)sum/data_size; // Sum of values over # of values
}

// Returns stdev (population) of current IntVec's values
float IntVec::standardDev(){
  unsigned long sum = 0; 
  float square_sum = 0;
  for(unsigned int i = 0; i < data_size; i++){
    sum+=data[i]; // Sum of values
  }
  float mean = (float)sum/data_size; // Calculate mean
  for(unsigned int i = 0; i < data_size; i++){ // Sum of difference of vals from 
    square_sum+=(data[i]-mean)*(data[i]-mean); // mean squared.
  }
  if(data_size<=1){
    return 0;
  }
  return sqrt(square_sum/data_size); // Square root of variance
}

// Returns new IntVec that is the sum of current and given IntVec's values
IntVec IntVec::add(const IntVec& rhs){
  IntVec sumVec; // new IntVec to store sum
  if(rhs.data_size != data_size){ // Check if IntVec sizes match. If not,
    return sumVec;                // return an empty IntVec.
  }
  for(unsigned int i = 0; i < data_size; i++){ // 
    sumVec.push_back(data[i]+rhs.data[i]);  // Push back sum of each space
  }
  return sumVec;
}

// Adds given num to every IntVec values and returns it as a new IntVec
IntVec IntVec::add(int number){
  IntVec sumVec;
  for(unsigned int i = 0; i < data_size; i++){
    sumVec.push_back(data[i]+number);
  }
  return sumVec;
}  

// Returns IntVec as string
string IntVec::getAsString(){
 string stringVec = "[";
 for(unsigned int i = 0; i < data_size; i++){
    int temp = data[i];
    string s;
    string t;
    while(temp/10!=0){
        t.push_back(temp%10+48);
        s.insert(0, t);
        t = "";
        temp = temp/10;
    }
    t.push_back(temp+48); 
    s.insert(0, t);
    stringVec.append(s);
    if(i != data_size-1){
      stringVec.push_back(','); // Trailing comma
      stringVec.push_back(' '); // and space
    }
  }
  stringVec.push_back(']'); // End bracket with no trailing comma
  return stringVec;
}

// Returns true if current IntVec and given IntVec are equal  
bool IntVec::equals(const IntVec& rhs){
  if(rhs.data_size != data_size){ // Return false if different size
    return 0;
  }
  for(unsigned int i = 0; i < data_size; i++){ // Return false if any values
    if(data[i]!=rhs.data[i]){                  // are different.
      return 0;
    }
  }
  return 1;
} 

// Appends given IntVec values to right side of current IntVec
IntVec IntVec::append(const IntVec& rhs){
  IntVec appendVec;
  for(unsigned int j = 0; j < data_size; j++){ // Copy current IntVec values
    if(appendVec.data_size == appendVec.data_cap){
      appendVec.addCap();
    }
    appendVec.data[j] = data[j];
    appendVec.data_size++;
  }
  int length = data_size;
  for(unsigned int j = 0; j < rhs.data_size; j++){ // Append rhs IntVec values
    if(appendVec.data_size == appendVec.data_cap){
      appendVec.addCap();
    }
    appendVec.data[length] = rhs.data[j];
    appendVec.data_size++;
    length++;
  }
  return appendVec;
}

//Increases data capacity by 5
void IntVec::addCap(){
  data_cap*=2; // Increase array capacity by 2x.
  int *temp = data;
  data = new int[data_cap];
  for (unsigned int i = 0; i < data_size; i++){ 
    data[i] = temp[i]; // Put data values into new array with greater cap
  }
  delete[] temp;
}
