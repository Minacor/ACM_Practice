

//a��������b��ѡȡ��
//��������ģ��û���漰�����������Կ�����ͬ�ඨ������Χ
long long C[20000][505];

long long comb(int a,int b){
   if(C[a][b])
      return C[a][b];
   if(a == b || b==0)
      return 1;
   return C[a][b]=(comb(a-1,b)+comb(a-1,b-1))%mod;
}
