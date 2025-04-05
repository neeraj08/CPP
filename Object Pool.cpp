#include <bits/stdc++.h>
class ObjectPoolManager;
class PooledObject;

using namespace std;


class PooledObject{
	public:
	//some vague values that this object has
	int some_value; 
	float some_value2;
	string some_value3;
	
	PooledObject(){ // constructor
		some_value=1;
		some_value2=2.3;
		some_value3="Hello";
	}
};

class ObjectPoolManager{
	public:
	int currentPoolSize;
	int maxPoolSize;
	
	//queue<PooledObject*> inUsePool;
	//not using inUsePool. Works in O(1) without it
	
	queue<PooledObject*> freePool;
	PooledObject* pooledObjects; // Note: use Vector instead and dynamically create new PooledObject(s) at runtime when needed ? 
	
	ObjectPoolManager(int poolSize = 40){
		currentPoolSize = 0;
		maxPoolSize = poolSize;
		pooledObjects = new PooledObject[maxPoolSize];//fixed sized pool
		for(int i=0;i<poolSize;i++) // initialize freePool with the whole array of pooledObjects
			freePool.push(&pooledObjects[i]); // store addresses of all pooled ojects
	}
	
	PooledObject* getPooledObject(){
		if(currentPoolSize<maxPoolSize){
			PooledObject* temp = freePool.front();
			freePool.pop();
		//	inUsePool.push(temp);
			currentPoolSize++;
			return temp;
		}
		else
			return nullptr;
	}
	
	void returnPooledObject(PooledObject * pooled){
		if(pooled){
	//	inUsePool.pop();
		freePool.push(pooled);
		currentPoolSize--;
		}
	}
};

int main(){
	ObjectPoolManager myPoolManager;

	PooledObject* myObject = myPoolManager.getPooledObject();
	//use as needed
	myPoolManager.returnPooledObject(myObject);

	return 0;
}
