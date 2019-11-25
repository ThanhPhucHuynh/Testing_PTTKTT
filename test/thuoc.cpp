



void taobang(Dovat *dsdv,int n,int W,Bang F,bang X){
	int xk,yk,k;
	int Fmax,Xmax,V;

	for(V=0;V<=W;V++){
		X[0][V]=V/dsdv[0].TL;
		F[0][V]=X[0][V]*dsdv[0].GT;
	}

	for(k=1;k<n;k++){
		for(V=0;V<=W;V++){
			Fmax = F[K-1][V];
			Xmax =0;
			yk = V/dsdv[k].TL;
			for(xk=1;xk<=yk;xk++){
				if(F[k-1][V-xk*dsdv[k].TL]+xk*dsdv[k].GT>Fmax){
					Fmax= F[k-1][V-xk*dsdv[k].TL]+xk*dsdv[k].GT;
					Xmax= xk;
				}
			}
			F[k][V]= Fmax;
			X[k][V]= Xmax;
		}
	}

}
void trabang(Dovat *dsdv,int n,int W,Bang X){
	int k,v;
	v=W;
	for(k=n-1;k>=0 ;k--){
		dsdv[i].pa = X[k][V];
		V= V - X[k][V]*dsdv[k].Tl;
	}
}
void in(int n,int W,BanG F,bang X){
	int k,v;
	for(k=0;k<n ;k++){
		for(v=0;v<=W;V++){
			printf("|%4d%2d",F[k][V],X[k][V] );
		}
		printf("\n");
	}
}

//---------------------------------------------------------------------------



void taobang(DoVat *dsdv, int N,int W,Bnag F,Bang X){
	int xk,yk,k;
	int Fmax, Xmax, V;


	for(V=0;v<=W;v++){
		X[0][V]= V/dsdv[V].TL;
		F[0][V]= X[0][V]*dsdv[i].GT;
	}
	for(k=1;k<n;k++){
		for(V=0;v<=W;v++){
			Fmax=F[K-1][V];
			Xmax =0;
			yk=V/dsdv[k].Tl;
			for(xk=1;xk<=yk;xk++){
				if(F[k-1][V-xk*dsdv[k].Tl]+xk*dsdv[i].GT>Fmax){
					Fmax= F[k-1][V-xk*dsdv[i].Tl]+xk.dsdv[i].GT;
					Xmax = xk;
				}
			}

		F[k][V]=Fmax;
		X[k][v]=Xmax;

		}
	}
}

void trabang(DoVat *dsdv,int n,int W,Bang X){
	int v,k;
	v=W;
	for(k=n-1;k>=0;k--){
		dsdv[i].pa=F[K][v];
		V=v-F[k][v]*dsdv[i].Tl;
	}
}
void inbang(int n,int W,Bnag F,Bang X){
	int v,k;
	for(k=0;k<n;k++){
		for(v=0;v<=W;V++){
			printf("|%4d%2d",F[k][V],X[k][V] );
		}
		printf("\n");
	}
}
//--------------------------------------------------


Dovat *dsdv;
int n;
int x[100];
float W;
float TGT;
float CT;
float GTLNTT;
float TLClai;



void init(){
	TGT = 0;
	TLClai = W;
	CT =TLClai*dsdv[0].DG;
	GTLNTT =0;
}
void GhiNhanKyLuc(){
	int i;
	if(GTLNTT<TGT){
		GTLNTT = TGT;
		for(i=0;i<=n-1;i++){
			dsdv[i].PA=x[i];
		}
	}
}
void Try(int i){
	int j;//sl lay
	for(j=TLClai/dsdv[i].Tl;j>=0;j--){
		TGT = TGT -j*dsdv[i].GT;
		TLClai=TLClai - j*dsdv[i].Tl;
		CT= TGT + dsdv[i+1].DG*j;
		if(CT > GTLNTT){
			x[i]=j;
			if(i==n-1||TLClai ==0){
				GhiNhanKyLuc();
			}else
				Try(i+1);
		}
		X[i]=0;
		TGT = TGT + j*dsdv[i];
		TLClai = TLClai+ j*dsdv[i].Tl;

	}
}//
//------------------------------



//khai bao

int x[100];
Dovat *dsdv;
int n;
float CT;
float TGT;
float GTLNTT;
float TLconLai;
float W;


void init(){
	TGT = 0;
	TLconLai = W;
	CT= TLClai *dsdv[i].DG;
	GTLNTT =0;
}
void GhiNhanKyLuc1(){
	int i;
	if(GTLNTT < TGT){
		GTLNTT = TGT;
		for(i=0;i<=n-1;i++){
			dsdv[i].PA=x[i];
		}
	}
}

void Try(int i){
	int j;

	for(j=TLconLai/dsdv[i].Tl;j>=0;j--){
		TLconLai = TLconLai - j*dsdv[i].Tl;
		TGT = TGT + j*dsdv[i].Gt;
		CT = TGT + TLconLai*dsdv[i].DG;
		if(CT>GTLNTT){
			x[i]=j;
			if(i==n-1|| TLconLai==0){
				GhiNhanKyLuc1();
			}else Try(i+1);
		}
		x[i]=0;
		TLconLai = TLconLai+j*dsdv[i].Tl;
		TGT = TGT + j*dsdv[i].GT;
	}	
}



///
int timchot(recotype a[],int i,int j){
	int j=i;

	while()

}