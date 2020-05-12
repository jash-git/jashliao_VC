CodeBlocks OPENCV 2.4.9 基本影像處理[彩色轉灰階(CB_OpenCV249_Rgb2Gray)]


資料來源:
https://cg2010studio.com/2011/06/06/opencv-%E8%BD%89%E6%8F%9B%E5%BD%B1%E5%83%8F%E7%82%BA%E7%81%B0%E9%9A%8E-transform-image-to-gray-level/
https://blog.csdn.net/kuweicai/article/details/73414138
https://cg2010studio.com/2013/03/22/opencv-iplimage-%E5%92%8C-mat-%E4%BA%92%E8%BD%89/

此範例是為了實現
	01.自己利用抓取像素方式撰寫彩色轉灰階 [IplImage]
	02.利用CV讀取影像彩色轉灰階 [Mat]
	03.比較上面兩種方法運算速度的差異
	04.IplImage 和 Mat 互轉
		// IplImage to Mat
		IplImage *img;
		 
		cv::Mat mat(img, 0);
		 
		// Mat to IplImage
		cv::Mat mat;
		 
		IplImage *img = IplImage(mat);	