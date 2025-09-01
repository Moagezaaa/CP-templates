ll a;cin>>a;
    str c="";
    while(a){
      int b=a%9;
      if(b>=4)b++;
      c+=b+'0';a/=9;
    }
    reverse(all(c));
    cout<<c;