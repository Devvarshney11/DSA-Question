// You have to play game of n turns. The purpose is to maximize your total score n turns

// Initially we to start with score = 0 and in the ith turn , you can either add i to score or 
// not add anything

// But there is restriction the score at any turn never be equal to x;

#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

int findScore(int n, int x)
{
    if(n == 1 && x == 1)
    return 0;
    int score = 0;
    for(int i = 1;i<=n;i++)
    {
        score += i;
        if(score == x)
        {
            score -= 1;
        }
    }
    return score;
}
int main()
{
    int n;
    int x;
    cin>>n>>x;
    int score = findScore(n,x);
    cout<<score;
    return 0;
}