
// imageproc_20210791View.h: Cimageproc20210791View 클래스의 인터페이스
//

#pragma once


class Cimageproc20210791View : public CScrollView
{
protected: // serialization에서만 만들어집니다.
	Cimageproc20210791View() noexcept;
	DECLARE_DYNCREATE(Cimageproc20210791View)

// 특성입니다.
public:
	Cimageproc20210791Doc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // 생성 후 처음 호출되었습니다.

// 구현입니다.
public:
	virtual ~Cimageproc20210791View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMenutest();
	afx_msg void OnPixelAdd();
	afx_msg void OnPixelSub();
	afx_msg void OnPixelMul();
	afx_msg void OnPixelDiv();
	afx_msg void OnPixelHistoEq();
	afx_msg void OnPixelContrastStretchin();
	afx_msg void OnPixelBinaryization();
	afx_msg void OnPixelTowImageAdd();
	void LoadTowImages();
	afx_msg void OnPixelTowImagesub();
	afx_msg void OnRegionSharpening();
	void convolve(unsigned char** inimg, unsigned char** outimg, int cols, int rows, float mask[3][3], int bias, int depth);
	afx_msg void OnResionSmoothing();
	afx_msg void OnRegionEmbossing();
	void LoadImageFile(CArchive& ar);
	afx_msg void OnRegionPrewitt();
	afx_msg void OnRegionRoberth();
	afx_msg void OnRegionSobel();
	afx_msg void OnRegionAverageFiltering();
	afx_msg void OnRegionMedianFiletering();
	afx_msg void OnMopologyColorToGray();
	afx_msg void OnMopologyBinarization();
	afx_msg void OnMopologyErosion();
	afx_msg void OnMopologyDilation();
	void CopyResultInput();
	void OnMopologyClosing();
	afx_msg void OnOnmopologyopening();
	afx_msg void OnOnmopologyclosing();
	afx_msg void OnGeometryZoominPixelCopy();
	afx_msg void OnGeometryZoominBilinearIntetpolation();
	afx_msg void OnGeometryZoomoutSubsampling();
	afx_msg void OnGeometryZoomoutMeanSub();
	afx_msg void OnGeometryAvgSampling();
};

#ifndef _DEBUG  // imageproc_20210791View.cpp의 디버그 버전
inline Cimageproc20210791Doc* Cimageproc20210791View::GetDocument() const
   { return reinterpret_cast<Cimageproc20210791Doc*>(m_pDocument); }
#endif

