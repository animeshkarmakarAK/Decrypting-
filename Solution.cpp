/*
submitted by : Animesh karmakar
Purpose:  To get  Paid Internship Opportunity On Machine Learning & Blockchain in Circle FinTech 
Date : 10 sep, 19

Overall Method :
The list of general tasks are 
1. Input price, height of tiles of back row and front row.

2. Sort the front row and back row data's in non-decreasing 
   order of price.

3. If the height constraint of problem doesn't meet for a tile
    iterate through the upper bound and lower bound of tiles 
    array and find a perfect one which also meet the non-decreasing
    order of price constraint. if not get output: impossible
    otherwise swap tiles data's.

4. print the rearranged front row and back row tiles indexes.

Coding explanation:   
                Only one row of tiles need to rearrage based on given constraints. 
                I take a structure and a 2-D vector as a type of this structure 
                and take the input of tiles price, height and also store primitive 
                indexes because need to output this rearranged indexes of tiles.
                Overload an operator to sort row's prices in non-decrasing order.
                Then iterate through all tiles to check that front row tiles meeting 
                the constraints with back row tiles.
*/

#include<bits/stdc++.h>

using namespace std;

struct Tile{
    int price, height, idx;
    bool operator<(const Tile& t) const { return price < t.price; }

};

bool constraint(int i, int k, vector<vector<Tile>> v)
{
        //only can swap the tiles which have same price to meet non-decreasing order price constraints 
        if(v[1][i].price == v[1][k].price)
        {
            // height constaints 
            if(v[1][k].height < v[0][i].height)
            return true;
            else return false;
            
        }
        else return false;
}

int main() 
{
    //input number of tiles
    int N;
    cin>>N;

    // 2-D vector to store tiles price, height and primitive index to tiles
    vector<vector<Tile>> v;

    //input back row and front row prices and heights of tiles
    for (int row = 0; row < 2; row++) {
      vector<Tile> T(N);
      for (int i = 0; i < N; i++) cin >> T[i].price;
      for (int i = 0; i < N; i++) cin >> T[i].height;
      for (int i = 0; i < N; i++) T[i].idx = i+1;

      //sort in non-decreasing order of price
      sort(T.begin(), T.end(), [] (const Tile& a, const Tile& b) -> bool { return a.price < b.price; });
      v.push_back(T);
 }


    for(int i = 0; i < N; i++) {

        // if front row tiles height is smaller or equal to back row tiles heights
        if(v[0][i].height <= v[1][i].height){

            //upper bound check for a perfect tile 
            bool got = false;
            int k = i + 1;
            while(k <= N) {
                if(constraint(i, k, v)){
                    swap(v[1][i], v[1][k]);
                    got = true;
                    break;
                }
                ++k;
            }

        //lower bound check for a perfect tiles 
            k = i;
            while(got == false && k > 0) {
                k--;
                if(constraint(i, k, v)) {
                    swap(v[1][i], v[1][k]);
                    got = true;
                }
            }

            // not possible to satisfies constraints so no ordering exists
            if(got == false)
            {
                cout<<"impossible"<<endl;
                return 0;
            }
        }
    }
    
    //print output indexes
    for(int row = 0; row < 2; row++){
    for(int i = 0; i < N; i++) {
        cout<<v[row][i].idx<<" ";
    }
        cout<<endl;
    }
    return 0;
}