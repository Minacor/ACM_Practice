

//a是总数，b是选取数
//这个组合数模板没有涉及到除法，所以可以用同余定理掐范围
long long C[20000][505];

long long comb(int a,int b){
   if(C[a][b])
      return C[a][b];
   if(a == b || b==0)
      return 1;
   return C[a][b]=(comb(a-1,b)+comb(a-1,b-1))%mod;
}
