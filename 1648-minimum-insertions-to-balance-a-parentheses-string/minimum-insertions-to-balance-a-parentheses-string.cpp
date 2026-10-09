/*class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();

        int open = 0;
        int ist = 0;

        for(int i=0; i<n; i++){
            if(s[i]=='(') open++; // (
            if(s[i]==')' && open==0){// )
                ist++;
                open++;
                i--;
                continue;
            }
            if(i<=n-2 && s[i]==')' && s[i+1]==')'){// (  ))
                open--;
                i++;
                continue;
            }
            if(i<=n-2 && s[i]==')' && s[i+1]=='('){// (  )(
                open--;
                ist++;
                continue;
            }
            if(i==n-1 && s[i]==')' && open>0){
                ist++;
                open--;
                continue;
            }
        }

        ist += 2*open;
        return ist;
    }
};*/


class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();

        int open = 0;
        int ist = 0;

        for(int i=0; i<n; i++){
            if(s[i]=='(') open++; // (
            else if(open==0){// )
                ist++;
                open++;
                i--;
            }
            else if(i<=n-2 && s[i+1]==')'){// (  ))
                open--;
                i++;
            }
            else if(s[i+1]=='('){// (  )(
                open--;
                ist++;
            }
            else{ // [..((..   .)]
                ist++;
                open--;
            }
        }

        ist += 2*open;
        return ist;
    }
};