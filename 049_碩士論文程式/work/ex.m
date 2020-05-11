function strobmov( freqs, durs, QT_fps, filename, nspokes )
%STROBMOV     make a strobe movie
%
%   freqs  = list of freqs for rotation (CCW)
%   durs   = how long each freq lasts
%              (NOTE: the sum of durs is the total duration)
%   QT_fps = frame rate for quicktime
%   filename = name for .mov file,
%             '*' means build default name
%   nspokes = number of spokes on the wheel
%
%=========
%%
write_GIF = 1;
write_MOV = 1;
%%
if nargin<4
   nspokes = 1;
   filename = ' ';
elseif nargin < 5
   if( isstr(filename) ), nspokes = 1; else, nspokes = ' '; end
end
if( isstr(nspokes) )
   tt = nspokes;
   nspokes = filename;
   filename = tt;
end
if( findstr(upper(filename),'.GIF') )
   write_MOV = 0;  filename = filename(1:length(filename)-4);
elseif( findstr(upper(filename),'.MOV') )
   write_GIF = 0;  filename = filename(1:length(filename)-4);
end
%%%widd = 200; hght = 100;
widd = 200; hght = widd/2;
widg = 150; htg = widg/2;
figure('Units', 'Pixels', 'resize','on',...
       'pos', [300 400 widd hght],...
       'numbertitle','off',	'name','Strobe Demo')
Font_axis = 12;
Font_labels = 11;
vvv = version;
if strcmp(vvv(1),'5'), eval('colordef none'), disp('v5'), end

% Generate the two pulses

LT = length(durs);
if length(durs)~=length(freqs)
   error('durs and freqs vectors must have the same length')
end

dt = 1/QT_fps;
nd = round( durs/dt );
dur_tot = dt*sum(nd);
tt = 0 : 1/QT_fps : dur_tot;
%%tt = ( 1:sum(nd) )*dt
ff = 0*tt;
nn = 1; ii = 1;
ff(1) = freqs(1);
while( ii<=LT )
   ff(nn+(1:nd(ii))) = freqs(ii)*ones(1,nd(ii));
   nn = nn + nd(ii);
   ii = ii+1;
end
phi = cumsum(ff)*dt;
phi = [0,phi(1:length(phi)-1)];

zz0 = exp( 2i*pi*phi );
nnn = (0:2*nspokes)';
nn2 = 1:2:2*nspokes-1;
spk = rem(nnn+1,2).*exp( i*pi/nspokes*nnn );
zz = 0.88*spk*zz0;
z0 = zeros(nspokes,1);
orig = 0;

cc0 = 1.0*exp(2i*pi*linspace(0,1,19));
rada = 1.2;
aa = [rada*exp(2i*pi*linspace(-0.075,-0.025,11)),NaN,...
        rada*exp(2i*pi*linspace(0.033,0.103,15))];
aan = aa(length(aa));
aadir = 1i*aan;
arr = aan + 0.1*[2*aadir aan -aan 2*aadir];

NQ = length(tt)
nq = 1;
Q = moviein(NQ,gcf);
SP = subplot('Position',[0.02 0.0 1.0 0.95]);
  plot(0),drawnow
colormap(gray)

subplot(SP)
   hpc = fill( real(cc0), imag(cc0), 'w' );
   hold on
   acolor = 'y';
   hpa1 = plot( aa );
   set( hpa1, 'LineWidth', 2, 'color', acolor );
   hpa2 = fill( real(arr), imag(arr), acolor );
   hpz = plot( [real(zz(:,1))], [imag(zz(:,1))], 'k',...
      real(zz(nn2,1)), imag(zz(nn2,1)), 'k.' );
   axis([-1 3 -1 1])
   axis off
   set(hpz, 'LineWidth', 3, 'MarkerSize', 40)
   txt2 = ['Fs = ',num2str(QT_fps),' fps'];
   ht2 = text(1.0, -0.9, txt2,...
       'FontWeight', 'bold', 'FontSize', 12, 'color', 'w' );
   ht1 = text( 1.05, 0, sprintf('%4.2f rev/s',ff(1)),...
          'FontWeight', 'bold', 'FontSize', 14, 'color', acolor );
   drawnow
   if write_MOV, Q(:,nq) = getframe(gcf); end;   nq=nq+1;
for kk = 2:length(tt)
   if kk>1
     if( ff(kk)~=ff(kk-1) )
	   if( strcmp(acolor,'y') ), acolor='c';
	   elseif( strcmp(acolor,'c') ), acolor = 'g';
	   else acolor = 'y'; end
	 end
   end
%%if exist('hxp'), clear hxp, end
   delete(hpc)
   cc = cc0*zz0(kk);
   hpc = fill( real(cc), imag(cc), 'w' );
   delete(hpa1); delete(hpa2)
   hpa1 = plot( aa );
   set( hpa1, 'LineWidth', 2, 'color', acolor );
   hpa2 = fill( real(arr), imag(arr), acolor );
   delete(hpz);
   hpz = plot( [real(zz(:,kk))], [imag(zz(:,kk))], 'k',...
      real(zz(nn2,kk)), imag(zz(nn2,kk)), 'k.' );
   axis([-1 3 -1 1])
   axis off
   set(hpz, 'LineWidth', 3, 'MarkerSize', 40)
   delete(ht1), delete(ht2)
   txt2 = ['Fs = ',num2str(QT_fps),' fps'];
   ht2 = text(1.0, -0.9, txt2,...
       'FontWeight', 'bold', 'FontSize', 12, 'color', 'w' );
   ht1 = text( 1.05, 0, sprintf('%4.2f rev/s',ff(kk)),...
          'FontWeight', 'bold', 'FontSize', 14, 'color', acolor );
   drawnow
   if write_MOV, Q(:,nq) = getframe(gcf); end;   nq=nq+1;
   if( write_GIF & ~strcmp(filename,' ') & nq>0.37*NQ )
      mm = findstr(upper(filename),'.MOV');
%%      if isempty(mm); mm = findstr(upper(filename),'.GIF');  end
%%	  if isempty(mm); mm = length(filename)+1;  end
      txt_gif = [filename,'.gif'];
	  set(ht1,'FontSize',12);  set(ht2,'FontSize',12);
	  pos_save = get(gcf,'Position');
	  set(gcf,'Position',[pos_save(1:2),widg,htg]);
      [GGG,ccc] = capture;
      gifwrite(GGG,ccc,txt_gif);
	  write_GIF = 0;
	  if ~write_MOV;  return;  end;
	  set(gcf,'Position',pos_save);
	  set(ht1,'FontSize',14);  set(ht2,'FontSize',12);
   end
end

nq = nq-1
if( nq ~= NQ )
   NQ, nq
   error('Wrong number of QT frames:')
end

if( ~strcmp(filename,' ') & write_MOV )
  if( strcmp(filename,'*') )
    txt = ['strobe',num2str(freqs(1)),'_at_',num2str(QT_fps),'.mov'];
  else
    txt = [filename,'.mov'];
  end
  qtwrite(Q,colormap,txt,QT_fps);
end
