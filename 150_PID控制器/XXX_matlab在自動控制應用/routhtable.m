function R = routhtable (b)
 
if(nargin<1), warning('No Input Argument') ; return
end
 
b = fliplr(b) ;      
ord = size(b,2)-1 ; 
 
rou_i = fix( fix(ord/2)*2 ) + 1 ;
rou_j = ceil((ord+1)/2) ;          
 
Ri = [ b(ord+1:-2:1) ; 
       b(ord:-2:1)  zeros( fix(( rou_i-1 )/ord) ) ] ;
 
R = sym( zeros(ord+1,rou_j) )  ;  R(ord+1:-1:ord, : ) = Ri ;
 
for n = ord-1:-1:2
for j = 1:round(n/2)
R(n,j) = ( R(n+1,1)*R(n+2,j+1)-R(n+1,j+1)*R(n+2,1) )/R(n+1) ;
end
end
R(1,1) = R(rou_i,rou_j) ;
 
R = simplify(R) ; R = flipud(R) ;  