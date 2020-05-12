//
// Sprite--貼圖零件
//
//		Copyright (c) 2000 Chihiro.SAKAMOTO (HyperWorks)
//
#include "StdAfx.h"
#include "DibSection.h"
#include "Sprite.h"

// 繪製貼圖零件
//
void CSprite::Draw(CDibSection &image)
{
	image.Mix(*dib, draw_pos, size, src_pos);
}

// 繪製貼圖零件(有裁切的)
//
void CSprite::Draw(CDibSection &image, const CRect &rect)
{
	CRect r(draw_pos, size);
	r &= rect;
	if (!r.IsRectEmpty()) {
		CPoint	src = src_pos;
		CPoint	dest = draw_pos;
		if (dest.x < r.left) {
			src.x += r.left - dest.x;
			dest.x = r.left;
		}
		if (dest.y < r.top) {
			src.y += r.top - dest.y;
			dest.y = r.top;
		}
		image.Mix(*dib, dest, r.Size(), src);
	}
}
