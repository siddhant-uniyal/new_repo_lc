class Solution {
public:
    vector<int> lexicalOrder(int n) {
       vector<int>ans{1};
        while(ans.size() < n){
            int next = ans.back() * 10; //no matter what , in pure lexico context , next lexico term is always the previous one with a 0

            while(next > n){ //now it has to be <= n , so go here to fix it
                next /= 10; //undo the appending of 0
                next += 1; //forced to do the least worse move than the best(just adding a 0) , hence do +1
                //if next ends in a 9 , now there can be a bunch of 0s in the suffix of n
                //this means that we have actually gone too far ahead , because , adding 1 to a number ending in 9 means that , down the line , one digit's value has increased. means , next + 1 has some digit greater than next. so next + 1 is definitely ahead of next , but , next + 1 itself is ahead of a guy , who is just next + 1 - (all the zeros). now , this guy is => some prefix of next + ((a digit of next) + 1). hence , in this case , remove all the zeros , because this guy is the real just next element.
                while(next%10 == 0)next /= 10; 
            }
            ans.push_back(next);
        }
       return ans;
    }
};