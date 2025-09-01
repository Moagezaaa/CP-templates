
const int MAX = 1e7 + 1;
vector<bool> is_prime(MAX, true);
 
void sieve() {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i < MAX; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j < MAX; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

void solve() {
    

   }
int primefactor(int num){
  int ans = 0;
  while (num%2==0)
  {
    num/=2;
    ans++;
  }
  for (int i = 3; i <= sqrt(num); i+=2)
  {
    while (num%i==0)
    {
      num/=i;
      ans++;
    }
  }
  if(num>1)ans++;
  return ans;
  
}