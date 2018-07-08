#include<iostream>
#include<vector>
using namespace std;

struct Edge
{
	int start;
	int end;
};


int N; // number of vertices
int M; //  number of edges
vector<Edge> store_edge;
vector<bool> adjacency_matrix;
vector<bool> visited;

bool test_edge(int start, int end)
{
	bool flag = false;

	if(adjacency_matrix[(start-1)*N+(end-1)]==true)    flag = true;
	if(adjacency_matrix[(start-1)+(end-1)*N]==true)    flag = true;

	return flag;
}

// DFS one range;
void DFS(int i)
{
	visited[i-1] = true;
	cout<<i<<" ";
	for(int j=1;j<=N;j++)
	{
		if((test_edge(i, j)==true)&&(visited[j-1]==false))
		{
			DFS(j);
		}
	}

}

// DFS all map;
void DFSTraverse()
{
	// initialize visited matrix;
	for(int i=1;i<=N;i++)
	{
		visited[i-1] = false;
	}


	for(int i=1;i<=N;i++)
	{
		if(visited[i-1]==false)
		{
			DFS(i);
		}
	}
}

// test connected graph;
bool test_connect()
{
	bool flag = true;

	DFS(1);

	for(int i=0;i<N;i++)
	{
		if(visited[i]==false)
		{
			flag = false;
			break;
		}
	}

	return flag;
}



int main()
{
// store edge and vertices ////////////////////////////////
	
	cin>>N;	
	cin>>M;

	store_edge.resize(M);
	for(int i=0;i<M;i++)
	{
		cin>>store_edge[i].start;
		cin>>store_edge[i].end;
	}


	// create adjacency matrix;
	for(int i=0;i<N*N;i++)
	{
		adjacency_matrix.push_back(false);
	}

	// save current amp in adjacency matrix;
	for(int i=0;i<M;i++)
	{
		int start = store_edge[i].start - 1;
		int end = store_edge[i].end - 1;

		adjacency_matrix[start*N + end] = true;
		adjacency_matrix[start + end*N] = true;
	}

//	cout<<test_edge(2, 1)<<endl;
//	cout<<test_edge(2, 4)<<endl;

	// generate visited point;
	visited.resize(N);
	for(int i=0;i<N;i++)
	{
		visited[i] = false;
	}



//	DFS(5); // test DFS one range;
//	DFSTraverse();

	bool result = test_connect();
	cout<<result<<endl;



	return 0;
}

/*
5 3
1 2
3 4
2 5
*/
