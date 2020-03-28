/*
  Bartosz Sobocki 28-03-2020
  Problem: find the size of the longest common subsequence
*/

#include <iostream>

int lcs_size(std::string A, std::string B){
    int n = A.size();
    int m = B.size();
    
    // zauważmy fakt, że dodając zbiory puste do tablicy
    // musimy dodać 1 do obu jej wymiarów
    int T[n+1][m+1];
    
    //zerowanie pierwszej kolumny
    for (int i=0; i<=n; i++)
        T[i][0] = 0;
    
    //zerowanie pierwszego wiersza 
    for (int j=0; j<=m; j++)
        T[0][j] = 0;
        
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++){
            if (A[i-1] == B[j-1])
                T[i][j] = T[i-1][j-1] + 1;
            else
                T[i][j] = std::max(T[i-1][j], T[i][j-1]);
        }
        
    return T[n][m];
}

int main()
{
  std::string A = "bbabaabba";
  std::string B = "abbacdag";
  std::cout<<nwp_size(A,B)<<std::endl;
  return 0;
}
