function DrawPoint(ctx, x, y) {
	ctx.beginPath();
	ctx.arc(x, y, 2, 0, Math.PI * 2, true);
	ctx.fill();
}

function DrawPointArray(ctx, x, y) {
	for (var i = 0, n = x.length; i < n; ++i)
		DrawPoint(ctx, x[i], y[i]);
}

function DrawVoronoiDiagram(canvas, ctx, x, y, w, farthest) {
	var r = new Array();
	var g = new Array();
	var b = new Array();
	r[0] = g[0] = b[0] = 63;
	for (var i = 1; i < x.length; ++i) {
		r[i] = 63 + (b[i-1] + 16) % 128;
		g[i] = r[i-1];
		b[i] = g[i-1];
	}

	var imageData = ctx.getImageData(0, 0, canvas.width, canvas.height);
	var data = imageData.data;
	var n = 0;
	for (var i = 0; i < canvas.height; ++i)
		for (var j = 0; j < canvas.width; ++j) {
			var mind = 10000000, p = 0;
			if (farthest) mind = 0;
			for (var k = 0; k < x.length; ++k) {
				var dx = x[k] - j, dy = y[k] - i;
				var d = (dx * dx + dy * dy);
				if (w) d /= w[k];
				if (!farthest && d < mind ||
					farthest && d > mind) {mind = d; p = k;}
			}
			data[n]     = r[p];
			data[n + 1] = g[p];
			data[n + 2] = b[p];
			data[n + 3] = 255;
			n += 4;
		}
	ctx.putImageData(imageData, 0, 0);

	ctx.fillStyle = "rgb(255,255,255)";
	DrawPointArray(ctx, x, y);
}

VoronoiDiagram1();
function VoronoiDiagram1() {
	var canvas = document.getElementById('VoronoiDiagram1');
	var ctx = canvas.getContext('2d');
	var x = [10,38,71,53,76,55,42,37,23];
	var y = [33,76,79,61,36,36,23,50,35];
	for (var i = 0; i < x.length; ++i) x[i] *= 2, y[i] *= 2;
	DrawVoronoiDiagram(canvas, ctx, x, y);
}

VoronoiDiagram2();
function VoronoiDiagram2() {
	var canvas = document.getElementById('VoronoiDiagram2');
	var ctx = canvas.getContext('2d');

	var n = 9;
	var x = new Array();
	var y = new Array();
	var t = Math.PI * 2 / n;
	for (var i = 0; i < n; ++i) {
		x[i] = 100 - 75 * Math.sin(t * i);
		y[i] = 100 - 75 * Math.cos(t * i);
	}
	x[n] = x[n+1] = y[n] = y[n+1] = 100;
	x[n] -= 15; x[n+1] += 15;
	DrawVoronoiDiagram(canvas, ctx, x, y);
}

VoronoiDiagram3();
function VoronoiDiagram3() {
	var canvas = document.getElementById('VoronoiDiagram3');
	var ctx = canvas.getContext('2d');

	var x = [10,38,71,53,76,55,42,37,23];
	var y = [33,76,79,61,36,36,23,50,35];
	for (var i = 0; i < x.length; ++i) x[i] *= 2, y[i] *= 2;
	DrawVoronoiDiagram(canvas, ctx, x, y, null, true);
}

VoronoiDiagram4();
function VoronoiDiagram4() {
	var canvas = document.getElementById('VoronoiDiagram4');
	var ctx = canvas.getContext('2d');

	var x = [10,38,71,53,76,55,42,37,23];
	var y = [33,76,79,61,36,36,23,50,35];
	var w = [ 1, 2, 3, 4, 1, 2, 3, 4, 1];
	for (var i = 0; i < x.length; ++i) x[i] *= 2, y[i] *= 2;
	DrawVoronoiDiagram(canvas, ctx, x, y, w);
}