function DrawPoint(ctx, x, y) {
	ctx.beginPath();
	ctx.arc(x, y, 2, 0, Math.PI * 2, true);
	ctx.fill();
}

function DrawPointArray(ctx, x, y) {
	for (var i = 0, n = x.length; i < n; ++i)
		DrawPoint(ctx, x[i], y[i]);
}

function DrawPolygon(ctx, x, y) {
	ctx.beginPath();
	ctx.moveTo(x[0], y[0]);
	for (var i = 1, n = x.length; i < n; ++i)
		ctx.lineTo(x[i], y[i]);
	ctx.closePath();
	ctx.stroke();
}

function DrawArc(ctx, x1, y1, x2, y2, cx, cy) {
	ctx.beginPath();
	ctx.moveTo(x1, y1);
	ctx.quadraticCurveTo(cx, cy, x2, y2);
	ctx.stroke();
}

function DrawArrow(ctx, x1, y1, x2, y2, len, angle, gap) {
	var slope = Math.atan2(y2 - y1, x2 - x1);
	x1 += gap * Math.cos(slope);
	y1 += gap * Math.sin(slope);
	x2 -= gap * Math.cos(slope);
	y2 -= gap * Math.sin(slope);

	ctx.beginPath();
	ctx.moveTo(x1, y1);
	ctx.lineTo(x2, y2);
	ctx.lineTo(x2 - len * Math.cos(slope-angle), y2 - len * Math.sin(slope-angle));
	ctx.moveTo(x2, y2);
	ctx.lineTo(x2 - len * Math.cos(slope+angle), y2 - len * Math.sin(slope+angle));
	ctx.stroke();
}

function DrawArcArrow(ctx, x1, y1, x2, y2, cpx, cpy, len, angle, gap) {
	var slope1 = Math.atan2(cpy - y1, cpx - x1);
	x1 += gap * Math.cos(slope1);
	y1 += gap * Math.sin(slope1);
	var slope2 = Math.atan2(y2 - cpy, x2 - cpx);
	x2 -= gap * Math.cos(slope2);
	y2 -= gap * Math.sin(slope2);

	ctx.beginPath();
	ctx.moveTo(x1, y1);
	ctx.quadraticCurveTo(cpx, cpy, x2, y2);
	ctx.lineTo(x2 - len * Math.cos(slope2 - angle), y2 - len * Math.sin(slope2 - angle));
	ctx.moveTo(x2, y2);
	ctx.lineTo(x2 - len * Math.cos(slope2 + angle), y2 - len * Math.sin(slope2 + angle));
	ctx.stroke();
}

function DrawText(ctx, text, x, y, cx, cy, gap) {
	var slope = Math.atan2(y - cy, x - cx);
	x += gap * Math.cos(slope);
	y += gap * Math.sin(slope);
	ctx.fillText(text, x, y);
}

function DrawX(ctx, x, y, len) {
	ctx.beginPath();
	ctx.moveTo(x - len, y - len);
	ctx.lineTo(x + len, y + len);
	ctx.moveTo(x - len, y + len);
	ctx.lineTo(x + len, y - len);
	ctx.stroke();
}

function InvertColor(ctx, canvas) {
	var imageData = ctx.getImageData(0, 0, canvas.width, canvas.height);
	var d = imageData.data;

	for (var i = 0, n = d.length; i < n; i += 4) {
		d[i]     = 255 - d[i];
		d[i + 1] = 255 - d[i + 1];
		d[i + 2] = 255 - d[i + 2];
	}

	ctx.putImageData(imageData, 0, 0);
}

ConvexHull();
function ConvexHull() {
	var ctx = document.getElementById('ConvexHull').getContext('2d');
	var x = [20,38,71,53,76,55,42,37,23];
	var y = [65,76,79,61,36,36,23,50,35];

	ctx.scale(1.5, 1.5);

	ctx.strokeStyle = "rgb(0,127,0)";
	DrawArc(ctx, 27, 88, 77, 90, 50, 98);
	DrawArc(ctx, 79, 91, 92, 24, 95, 80);
	DrawArc(ctx, 90, 24, 24, 13, 63,  3);
	DrawArc(ctx, 25, 13,  5, 45, 10, 26);
	DrawArc(ctx,  5, 49, 23, 87, 10, 80);
	DrawArrow(ctx, 22, 86, 25, 77, 5, Math.PI / 3, 0);
	DrawArrow(ctx, 62, 93, 62, 80, 7, Math.PI / 4, 0);
	DrawArrow(ctx, 91, 66, 79, 63, 6, Math.PI / 3, 0);
	DrawArrow(ctx, 93, 41, 84, 42, 5, Math.PI / 3, 0);
	DrawArrow(ctx, 72, 15, 67, 24, 4, Math.PI / 3, 0);
	DrawArrow(ctx, 30, 12, 32, 23, 5, Math.PI / 5, 0);
	DrawArrow(ctx,  8, 39, 18, 46, 8, Math.PI / 6, 0);

	ctx.fillStyle = "rgb(0,0,0)";
	DrawPointArray(ctx, x, y);

	ctx.translate(100, 0);

	ctx.strokeStyle = "rgb(0,127,0)";
	ctx.beginPath();
	ctx.moveTo(x[1], y[1]);
	ctx.quadraticCurveTo(68, 91, 84, 90);
	ctx.quadraticCurveTo(95, 90, 85, 25);
	ctx.quadraticCurveTo(48, 10, 22, 19);
	ctx.stroke();
	DrawArcArrow(ctx, 22, 19, 19, 82, 0, 70, 8, Math.PI / 4, 0);

	ctx.fillStyle = "rgb(0,0,0)";
	DrawPointArray(ctx, x, y);

	ctx.translate(100, 0);

	ctx.strokeStyle = "rgb(0,127,0)";
	ctx.beginPath();
	ctx.moveTo(x[0] - 2, y[0] + 1);
	ctx.lineTo(x[1]    , y[1] + 3);
	ctx.lineTo(x[2] + 2, y[2] + 2);
	ctx.lineTo(x[4] + 2, y[4] - 1);
	ctx.lineTo(x[6]    , y[6] - 2);
	ctx.lineTo(x[8] - 2, y[8] - 1);
	ctx.closePath();
	ctx.stroke();

	ctx.fillStyle = "rgb(0,0,0)";
	DrawPointArray(ctx, x, y);
}

JarvisMarch();
function JarvisMarch() {
	var ctx = document.getElementById("Jarvis'March").getContext('2d');
	var x = [37,74,82,32,17,38,53,54];
	var y = [77,66,30,22,51,42,61,37];

	ctx.scale(1.5, 1.5);

	ctx.strokeStyle = "rgb(0,127,0)";
	DrawArcArrow(ctx, x[0], y[0], x[0], y[0] + 15, x[0] - 40, y[0] + 10, 8, Math.PI / 4, 5);

	ctx.fillStyle = "rgb(0,127,0)";
	ctx.font = "10pt Arial";
	ctx.fillText("起點", x[0], y[0] + 15);

	ctx.fillStyle = "rgb(0,0,0)";
	DrawPointArray(ctx, x, y);

	ctx.translate(100, 0);
	ctx.strokeStyle = "rgb(0,127,0)";
	for (var i = 0; i < 4; ++i)
		DrawArrow(ctx, x[i], y[i], x[i+1], y[i+1], 8, Math.PI / 8, 5);
	DrawArcArrow(ctx, x[4], y[4], x[0], y[0], x[4] - 15, y[4] + 30, 8, Math.PI / 8, 8);

	ctx.fillStyle = "rgb(0,127,0)";
	ctx.fillText("起點", x[0], y[0] + 15);

	ctx.fillStyle = "rgb(0,0,0)";
	DrawPointArray(ctx, x, y);
}

GrahamScan1();
function GrahamScan1() {
	var ctx = document.getElementById("Graham'sScan1").getContext('2d');
	var x = [37,53,74,82,54,32,38,17];
	var y = [77,61,66,30,37,22,42,51];
	var cx = 48, cy = 48;

	ctx.scale(1.5, 1.5);

	ctx.strokeStyle = "rgb(0,0,255)";
	for (var i = 0, n = x.length; i < n; ++i) {
		ctx.beginPath();
		ctx.moveTo(cx, cy);
		ctx.lineTo(x[i], y[i]);
		ctx.stroke();
	}

	ctx.fillStyle = "rgb(0,127,0)";
	ctx.font = "600 8pt Times New Roman";
	ctx.textAlign = "center";
	ctx.textBaseline  = "middle";
	for (var i = 0, n = x.length; i < n; ++i)
		DrawText(ctx, i.toString(), x[i], y[i], cx, cy, 9);

	ctx.fillStyle = "rgb(0,0,0)";
	DrawPointArray(ctx, x, y);

	ctx.fillStyle = "rgb(0,127,0)";
	ctx.translate(100, 0);
	for (var i = 3, n = x.length; i < n; ++i)
		DrawText(ctx, i.toString(), x[i], y[i], cx, cy, 9);

	ctx.strokeStyle = "rgb(0,127,0)";
	DrawArcArrow(ctx, x[0], y[0], x[1], y[1], x[0] + 15, y[0] + 25, 12, Math.PI / 6, 5);
	DrawArcArrow(ctx, x[1], y[1], x[2], y[2], x[2] + 12, y[2] + 32, 8, Math.PI / 7, 5);
	DrawArcArrow(ctx, x[2], y[2], x[3], y[3], x[2] + 15, y[2] - 5, 10, Math.PI / 8, 5);

	ctx.strokeStyle = "rgb(0,0,255)";
	for (var i = 0, n = x.length; i < n; ++i) {
		ctx.beginPath();
		ctx.moveTo(cx, cy);
		ctx.lineTo(x[i], y[i]);
		ctx.stroke();
	}

	ctx.fillStyle = "rgb(0,0,0)";
	DrawPointArray(ctx, x, y);

	ctx.strokeStyle = "rgba(255,0,0,.8)";
	ctx.lineWidth = 2;
	DrawX(ctx, x[1], y[1], 4);
}

GrahamScan2();
function GrahamScan2() {
	var ctx = document.getElementById("Graham'sScan2").getContext('2d');
	var x = [37,74,53,82,54,38,32,17];
	var y = [77,66,61,30,37,42,22,51];
	var o = [0,2,1,3,4,6,5,7];
	var cx = 48, cy = 48;

	ctx.scale(1.5, 1.5);

	ctx.strokeStyle = "rgb(0,0,255)";
	for (var i = 0, n = x.length; i < n; ++i) {
		ctx.beginPath();
		ctx.moveTo(cx, cy);
		ctx.lineTo(x[i], y[i]);
		ctx.stroke();
	}

	ctx.fillStyle = "rgb(0,127,0)";
	ctx.font = "600 8pt Times New Roman";
	ctx.textAlign = "center";
	ctx.textBaseline  = "middle";
	for (var i = 0, n = x.length; i < n; ++i)
		DrawText(ctx, i.toString(), x[o[i]], y[o[i]], cx, cy, 9);

	var red = [1,1,0,1,0,0,1,1];
	for (var i = 0, n = x.length; i < n; ++i) {
		if (red[i]) ctx.fillStyle = "rgb(255,0,0)";
		else        ctx.fillStyle = "rgb(0,0,0)";
		DrawPoint(ctx, x[i], y[i]);
	}

	ctx.fillStyle = "rgb(0,127,0)";
	ctx.translate(100, 0);
	DrawText(ctx, '0', x[0], y[0], x[4], y[4], 9);
	DrawText(ctx, '1', x[1], y[1], x[0], y[0], 9);
	DrawText(ctx, '2', x[2], y[2], x[7], y[7], 9);
	for (var i = 3, n = x.length; i < n; ++i)
		DrawText(ctx, i.toString(), x[i], y[i], x[0], y[0], 9);

	ctx.strokeStyle = "rgb(0,0,255)";
	for (var i = 0, n = x.length; i < n; ++i) {
		ctx.beginPath();
		ctx.moveTo(x[0], y[0]);
		ctx.lineTo(x[i], y[i]);
		ctx.stroke();
	}

	for (var i = 0, n = x.length; i < n; ++i) {
		if (red[i]) ctx.fillStyle = "rgb(255,0,0)";
		else        ctx.fillStyle = "rgb(0,0,0)";
		DrawPoint(ctx, x[i], y[i]);
	}
}

GrahamScan3();
function GrahamScan3() {
	var ctx = document.getElementById("Graham'sScan3").getContext('2d');
	var x = [37,74,53,82,54,38,32,17];
	var y = [77,66,61,30,37,42,22,51];
	var o = [0,2,4,6,1,3,5,7];

	ctx.scale(1.5, 1.5);

	ctx.fillStyle = "rgb(0,127,0)";
	ctx.font = "600 8pt Times New Roman";
	ctx.textAlign = "center";
	ctx.textBaseline  = "middle";
	for (var i = 0, n = x.length; i < n; ++i)
		DrawText(ctx, i.toString(), x[o[i]], y[o[i]], x[o[i]] - 10, 0, 9);

	ctx.fillStyle = "rgb(0,0,0)";
	DrawPointArray(ctx, x, y);

	ctx.fillStyle = "rgb(0,127,0)";
	ctx.translate(100, 0);
	for (var i = 0, n = x.length; i < n; ++i)
		DrawText(ctx, i.toString(), x[o[i]], y[o[i]], x[o[i]] - 10, 0, 9);

	ctx.strokeStyle = "rgb(255,0,0)";
	ctx.beginPath();
	ctx.moveTo(x[0], y[0]);
	ctx.lineTo(x[1], y[1]);
	ctx.lineTo(x[5], y[5]);
	ctx.lineTo(x[7], y[7]);
	ctx.closePath();
	ctx.stroke();

	ctx.fillStyle = "rgb(0,0,0)";
	DrawPointArray(ctx, x, y);
}

GrahamScan4();
function GrahamScan4() {
	var ctx = document.getElementById("Graham'sScan4").getContext('2d');
	var x = [37,74,53,82,54,38,32,17];
	var y = [77,66,61,30,37,42,22,51];

	ctx.scale(1.5, 1.5);

	ctx.strokeStyle = "rgb(0,0,255)";
	ctx.beginPath();
	ctx.moveTo(x[7], y[7]);
	ctx.lineTo(x[0], y[0]);
	ctx.lineTo(x[1], y[1]);
	ctx.stroke();

	ctx.fillStyle = "rgb(0,0,0)";
	DrawPointArray(ctx, x, y);

	ctx.fillStyle = "rgb(0,127,0)";
	ctx.font = "600 8pt Times New Roman";
	ctx.fillText("夾角必小於180度", x[0] - 30, y[0] + 15);
}

GrahamScan5();
function GrahamScan5() {
	var ctx = document.getElementById("Graham'sScan5").getContext('2d');
	var x = [37,74,82,32,67,32,44,17];
	var y = [77,66,30,22,47,56,40,51];

	ctx.scale(1.5, 1.5);

	ctx.strokeStyle = "rgb(0,0,255)";
	DrawPolygon(ctx, x, y);

	ctx.fillStyle = "rgb(0,0,0)";
	DrawPointArray(ctx, x, y);

	ctx.fillStyle = "rgb(0,127,0)";
	ctx.font = "600 8pt Times New Roman";
	ctx.textAlign = "center";
	ctx.textBaseline = "top";
	ctx.fillText("簡單多邊形", 50, 0 + 5);
	ctx.textBaseline = "bottom";
	ctx.fillText("錯誤例子", 50, 100 - 5);

	ctx.translate(100, 0);
	var x = [21,60,78,71,49,27,35];
	var y = [73,75,49,21,42,23,53];

	ctx.strokeStyle = "rgb(0,0,255)";
	DrawPolygon(ctx, x, y);

	ctx.fillStyle = "rgb(0,0,0)";
	DrawPointArray(ctx, x, y);

	ctx.fillStyle = "rgb(0,127,0)";
	ctx.textBaseline = "top";
	ctx.fillText("星狀多邊形", 50, 0 + 5);
	ctx.textBaseline = "bottom";
	ctx.fillText("正確例子", 50, 100 - 5);
}

GrahamScan6();
function GrahamScan6() {
	var ctx = document.getElementById("Graham'sScan6").getContext('2d');
	var x = [47,68,78,93,73,67,46,54,43,25,27,32,40];
	var y = [77,65,59,50,25,47,41,11,22,20,51,58,68];
	var cx = 48, cy = 48;

	ctx.scale(1.5, 1.5);

	ctx.strokeStyle = "rgb(0,0,255)";
	ctx.beginPath();
	ctx.moveTo(x[9], y[9]);
	ctx.lineTo(x[10], y[10]);
	ctx.lineTo(x[0], y[0]);
	ctx.lineTo(x[3], y[3]);
	ctx.lineTo(x[4], y[4]);
	ctx.stroke();

	ctx.fillStyle = "rgb(0,127,0)";
	ctx.font = "600 8pt Times New Roman";
	ctx.textAlign = "center";
	ctx.textBaseline  = "middle";
	for (var i = 10, n = x.length; i < n; ++i)
		DrawText(ctx, 'M-' + (n-i).toString(), x[i], y[i], x[i]+5, y[i]-1, 15);
	for (var i = 0; i < 4; ++i)
		DrawText(ctx, i.toString(), x[i], y[i], x[i]-1, y[i]-5, 9);

	ctx.fillStyle = "rgb(0,0,0)";
	DrawPointArray(ctx, x, y);
}