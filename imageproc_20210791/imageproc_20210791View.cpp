
// imageproc_20210791View.cpp: Cimageproc20210791View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "imageproc_20210791.h"
#endif

#include "imageproc_20210791Doc.h"
#include "imageproc_20210791View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cimageproc20210791View

IMPLEMENT_DYNCREATE(Cimageproc20210791View, CScrollView)

BEGIN_MESSAGE_MAP(Cimageproc20210791View, CScrollView)
	ON_COMMAND(ID_PIXEL_ADD, &Cimageproc20210791View::OnPixelAdd)
	ON_COMMAND(ID_PIXEL_SUB, &Cimageproc20210791View::OnPixelSub)
	ON_COMMAND(ID_PIXEL_MUL, &Cimageproc20210791View::OnPixelMul)
	ON_COMMAND(ID_PIXEL_DIV, &Cimageproc20210791View::OnPixelDiv)
	ON_COMMAND(ID_PIXEL_HISTO_EQ, &Cimageproc20210791View::OnPixelHistoEq)
	ON_COMMAND(ID_PIXEL_CONTRAST_STRETCHIN, &Cimageproc20210791View::OnPixelContrastStretchin)
	ON_COMMAND(ID_PIXEL_BINARYIZATION, &Cimageproc20210791View::OnPixelBinaryization)
	ON_COMMAND(ID_PIXEL_TOW_IMAGE_ADD, &Cimageproc20210791View::OnPixelTowImageAdd)
	ON_COMMAND(ID_PIXEL_Tow_Image_sub, &Cimageproc20210791View::OnPixelTowImagesub)
	ON_COMMAND(ID_REGION_SHARPENING, &Cimageproc20210791View::OnRegionSharpening)
	ON_COMMAND(ID_RESION_SMOOTHING, &Cimageproc20210791View::OnResionSmoothing)
	ON_COMMAND(ID_REGION_EMBOSSING, &Cimageproc20210791View::OnRegionEmbossing)
	ON_COMMAND(ID_REGION_PREWITT, &Cimageproc20210791View::OnRegionPrewitt)
	ON_COMMAND(ID_REGION_ROBERTH, &Cimageproc20210791View::OnRegionRoberth)
	ON_COMMAND(ID_REGION_SOBEL, &Cimageproc20210791View::OnRegionSobel)
	ON_COMMAND(ID_REGION_AVERAGE_FILTERING, &Cimageproc20210791View::OnRegionAverageFiltering)
	ON_COMMAND(ID_REGION_MEDIAN_FILETERING, &Cimageproc20210791View::OnRegionMedianFiletering)
	ON_COMMAND(ID_MOPOLOGY_COLOR_TO_GRAY, &Cimageproc20210791View::OnMopologyColorToGray)
	ON_COMMAND(ID_MOPOLOGY_BINARIZATION, &Cimageproc20210791View::OnMopologyBinarization)
	ON_COMMAND(ID_MOPOLOGY_EROSION, &Cimageproc20210791View::OnMopologyErosion)
	ON_COMMAND(ID_MOPOLOGY_DILATION, &Cimageproc20210791View::OnMopologyDilation)
	ON_COMMAND(ID_OnMopologyOpening, &Cimageproc20210791View::OnOnmopologyopening)
	ON_COMMAND(ID_OnMopologyClosing, &Cimageproc20210791View::OnOnmopologyclosing)
	ON_COMMAND(ID_GEOMETRY_ZOOMIN_PIXEL_COPY, &Cimageproc20210791View::OnGeometryZoominPixelCopy)
	ON_COMMAND(ID_GEOMETRY_ZOOMIN_BILINEAR_INTETPOLATION, &Cimageproc20210791View::OnGeometryZoominBilinearIntetpolation)
	ON_COMMAND(ID_GEOMETRY_ZOOMOUT_SUBSAMPLING, &Cimageproc20210791View::OnGeometryZoomoutSubsampling)
	ON_COMMAND(ID_GEOMETRY_ZOOMOUT_MEAN_SUB, &Cimageproc20210791View::OnGeometryZoomoutMeanSub)
	ON_COMMAND(ID_GEOMETRY_AVG_SAMPLING, &Cimageproc20210791View::OnGeometryAvgSampling)
END_MESSAGE_MAP()

// Cimageproc20210791View 생성/소멸

Cimageproc20210791View::Cimageproc20210791View() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

Cimageproc20210791View::~Cimageproc20210791View()
{
}

BOOL Cimageproc20210791View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CScrollView::PreCreateWindow(cs);
}

// Cimageproc20210791View 그리기

void Cimageproc20210791View::OnDraw(CDC* pDC)
{
	Cimageproc20210791Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	/*pDC->TextOutA(100, 100, _T("화면에 추력되는 메세지!"));
																	2023_9_12_오전에 잠깐 함
	pDC->Rectangle(50, 10, 200, 300);*/
	int x, y;
	if (pDoc->InputImg != NULL) {
		/*for (y = 0; y < pDoc->ImageHeight; y++) {  그림 그릴때 for문 안에서 IF문 돌리는거
			for (x = 0; x < pDoc->ImageWidth; x++) {
				if (pDoc->depth == 1) {
					pDC->SetPixel(x, y, RGB(pDoc->InputImg[y][x], pDoc->InputImg[y][x], pDoc->InputImg[y][x]));
				}
				else
				{
					pDC->SetPixel(x, y, RGB(pDoc->InputImg[y][3*x+0], pDoc->InputImg[y][3 * x + 1], pDoc->InputImg[y][3 * x + 2]));
				}				
			}
		}*/

		if (pDoc->depth == 1) {
			for (y = 0; y < pDoc->ImageHeight; y++) {
				for (x = 0; x < pDoc->ImageWidth; x++) {
					pDC->SetPixel(x, y, RGB(pDoc->InputImg[y][x], pDoc->InputImg[y][x], pDoc->InputImg[y][x]));
				}
			}
		}
		else {
			for (y = 0; y < pDoc->ImageHeight; y++) {
				for (x = 0; x < pDoc->ImageWidth; x++) {
					pDC->SetPixel(x, y, RGB(pDoc->InputImg[y][3*x+0], pDoc->InputImg[y][3 * x + 1], pDoc->InputImg[y][3 * x + 2]));
				}
			}
		}
		
	}
	if (pDoc->ResultImg != NULL) {
		if (pDoc->depth == 1) {
			for (y = 0; y < pDoc->ImageHeight; y++) {
				for (x = 0; x < pDoc->ImageWidth; x++) {
					pDC->SetPixel(pDoc->ImageWidth + 20 + x, y, RGB(pDoc->ResultImg[y][x], pDoc->ResultImg[y][x], pDoc->ResultImg[y][x]));
				}
			}
		}else {
			for (y = 0; y < pDoc->ImageHeight; y++) {
				for (x = 0; x < pDoc->ImageWidth; x++) {
					pDC->SetPixel(pDoc->ImageWidth + 20 + x, y, RGB(pDoc->ResultImg[y][3 * x + 0], pDoc->ResultImg[y][3 * x + 1], pDoc->ResultImg[y][3 * x +2]));
				}
			}
		}
		
	}
	if (pDoc->InputImg2 != NULL) {
		if (pDoc->depth == 1) {
			for (y = 0; y < pDoc->ImageHeight; y++) {
				for (x = 0; x < pDoc->ImageWidth; x++) {
					pDC->SetPixel(2 * (pDoc->ImageWidth + 20) + x, y, RGB(pDoc->InputImg2[y][x], pDoc->InputImg2[y][x], pDoc->InputImg2[y][x]));
				}
			}
		}
		else {
			for (y = 0; y < pDoc->ImageHeight; y++) {
				for (x = 0; x < pDoc->ImageWidth; x++) {
					pDC->SetPixel(2 * (pDoc->ImageWidth + 20) + x, y, RGB(pDoc->InputImg2[y][3*x +0], pDoc->InputImg2[y][3 * x + 1], pDoc->InputImg2[y][3 * x + 2]));
				}
			}
		}
		
	}
	
	if (pDoc->gResultImg != NULL) {
		if (pDoc->depth == 1) {
			for (y = 0; y < pDoc->gImageHeight; y++) {
				for (x = 0; x < pDoc->gImageWidth; x++) {
					pDC->SetPixel(x, pDoc->ImageHeight + 20 + y, RGB(pDoc->gResultImg[y][x], pDoc->gResultImg[y][x], pDoc->gResultImg[y][x]));
				}
			}
		}
		else {
			for (y = 0; y < pDoc->gImageHeight; y++) {
				for (x = 0; x < pDoc->gImageWidth; x++) {
					pDC->SetPixel(x, pDoc->ImageHeight + 20 + y, RGB(pDoc->gResultImg[y][3 * x + 0], pDoc->gResultImg[y][3 * x + 1], pDoc->gResultImg[y][3 * x + 2]));
				}
			}
		}

	}
}

void Cimageproc20210791View::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: 이 뷰의 전체 크기를 계산합니다.
	sizeTotal.cx = sizeTotal.cy = 2048;
	SetScrollSizes(MM_TEXT, sizeTotal);
}


// Cimageproc20210791View 진단

#ifdef _DEBUG
void Cimageproc20210791View::AssertValid() const
{
	CScrollView::AssertValid();
}

void Cimageproc20210791View::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

Cimageproc20210791Doc* Cimageproc20210791View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cimageproc20210791Doc)));
	return (Cimageproc20210791Doc*)m_pDocument;
}
#endif //_DEBUG


void Cimageproc20210791View::OnPixelAdd()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.


	Cimageproc20210791Doc* pDoc = GetDocument();
	if (pDoc->InputImg == NULL) return;

	int x, y, value;
	for (y = 0; y < pDoc->ImageHeight; y++) {                             
		for (x = 0; x < pDoc->ImageWidth * pDoc->depth; x++) {                  //--------------- 여기 참고해서 전부 고쳐야한다↓
			
			if (pDoc->depth == 1) {
				value = pDoc->InputImg[y][x] + 100;
				if (value > 255) value = 255;
				else if (value < 0) value = 0;
				pDoc->ResultImg[y][x] = value;
			} else{
				value = pDoc->InputImg[y][3*x + 0] + 100;
				if (value > 255) value = 255;
				else if (value < 0) value = 0;
				pDoc->ResultImg[y][3*x + 0] = value;
				value = pDoc->InputImg[y][3 * x + 1] + 100;
				if (value > 255) value = 255;
				else if (value < 0) value = 0;
				pDoc->ResultImg[y][3 * x + 1] = value;
				value = pDoc->InputImg[y][3 * x + 2] + 100;
				if (value > 255) value = 255;
				else if (value < 0) value = 0;
				pDoc->ResultImg[y][3 * x + 2] = value;
			}
		}
	}
	Invalidate();
}


void Cimageproc20210791View::OnPixelSub()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	Cimageproc20210791Doc* pDoc = GetDocument();

	/*for (y = 0; y < 256; y++) {		기존에 했던 코드
		for (x = 0; x < 256; x++) {

			value = pDoc->InputImg[y][x] - 40;
			if (value > 255) value = 255;
			else if (value < 0) value = 0;
			pDoc->ResultImg[y][x] = value;
		}
	}*/
	//-----------새로 고친 코드----------------------------- 뺴기 코드
	int x, y, value;
	for (y = 0; y < pDoc->ImageHeight; y++) {
		for (x = 0; x < pDoc->ImageWidth * pDoc->depth; x++) {

			if (pDoc->depth == 1) {
				value = pDoc->InputImg[y][x] - 40;
				if (value > 255) value = 255;
				else if (value < 0) value = 0;
				pDoc->ResultImg[y][x] = value;
			}
			else {
				value = pDoc->InputImg[y][3 * x + 0] - 40;
				if (value > 255) value = 255;
				else if (value < 0) value = 0;
				pDoc->ResultImg[y][3 * x + 0] = value;
				value = pDoc->InputImg[y][3 * x + 1] - 40;
				if (value > 255) value = 255;
				else if (value < 0) value = 0;
				pDoc->ResultImg[y][3 * x + 1] = value;
				value = pDoc->InputImg[y][3 * x + 2] - 40;
				if (value > 255) value = 255;
				else if (value < 0) value = 0;
				pDoc->ResultImg[y][3 * x + 2] = value;
			}
		}
	}
	Invalidate();
}


void Cimageproc20210791View::OnPixelMul()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	Cimageproc20210791Doc* pDoc = GetDocument();

	/*int x, y, value;
	for (y = 0; y < 256; y++) {			기존에 했던 코드
		for (x = 0; x < 256; x++) {

			value = pDoc->InputImg[y][x] * 1.2;
			if (value > 255) value = 255;
			else if (value < 0) value = 0;
			pDoc->ResultImg[y][x] = value;
		}
	}*/
	//-----------새로 고친 코드----------------------------- 곱하기 코드
	int x, y, value;
	for (y = 0; y < pDoc->ImageHeight; y++) {
		for (x = 0; x < pDoc->ImageWidth * pDoc->depth; x++) {

			if (pDoc->depth == 1) {
				value = pDoc->InputImg[y][x] * 1.2;
				if (value > 255) value = 255;
				else if (value < 0) value = 0;
				pDoc->ResultImg[y][x] = value;
			}
			else {
				value = pDoc->InputImg[y][3 * x + 0] * 1.2;
				if (value > 255) value = 255;
				else if (value < 0) value = 0;
				pDoc->ResultImg[y][3 * x + 0] = value;
				value = pDoc->InputImg[y][3 * x + 1] * 1.2;
				if (value > 255) value = 255;
				else if (value < 0) value = 0;
				pDoc->ResultImg[y][3 * x + 1] = value;
				value = pDoc->InputImg[y][3 * x + 2] * 1.2;
				if (value > 255) value = 255;
				else if (value < 0) value = 0;
				pDoc->ResultImg[y][3 * x + 2] = value;
			}
		}
	}
	Invalidate();
}


void Cimageproc20210791View::OnPixelDiv()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	Cimageproc20210791Doc* pDoc = GetDocument();

	/*int x, y, value;			기존에 했던 코드
	for (y = 0; y < 256; y++) {
		for (x = 0; x < 256; x++) {

			value = pDoc->InputImg[y][x] / 1.2;
			if (value > 255) value = 255;
			else if (value < 0) value = 0;
			pDoc->ResultImg[y][x] = value;
		}
	}*/
	//-----------새로 고친 코드----------------------------- 나누기 코드
	int x, y, value;
	for (y = 0; y < pDoc->ImageHeight; y++) {
		for (x = 0; x < pDoc->ImageWidth * pDoc->depth; x++) {

			if (pDoc->depth == 1) {
				value = pDoc->InputImg[y][x] / 1.2;
				if (value > 255) value = 255;
				else if (value < 0) value = 0;
				pDoc->ResultImg[y][x] = value;
			}
			else {
				value = pDoc->InputImg[y][3 * x + 0] / 1.2;
				if (value > 255) value = 255;
				else if (value < 0) value = 0;
				pDoc->ResultImg[y][3 * x + 0] = value;
				value = pDoc->InputImg[y][3 * x + 1] / 1.2;
				if (value > 255) value = 255;
				else if (value < 0) value = 0;
				pDoc->ResultImg[y][3 * x + 1] = value;
				value = pDoc->InputImg[y][3 * x + 2] / 1.2;
				if (value > 255) value = 255;
				else if (value < 0) value = 0;
				pDoc->ResultImg[y][3 * x + 2] = value;
			}
		}
	}
	Invalidate();
}


void Cimageproc20210791View::OnPixelHistoEq()
{
	Cimageproc20210791Doc* pDoc = GetDocument();
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	int x, y, i, k;
	int acc_hist;
	int N = pDoc->ImageHeight * pDoc->ImageWidth;   //256 이미지 높이 길이로 다 바꿔야 한다.
	int hist[256], sum[256];  // 이건 그대로 있어야한다.
	
	for (i = 0; i < 256; i++) {  // 이것도 바뀌면 안된다
		hist[i] = 0;                // 히스토그램 초기화
	}

	//히스토그램 구하기
	for (y = 0; y < pDoc->ImageHeight; y++) {
		for (x = 0; x < pDoc->ImageWidth * pDoc->depth; x++) {
			k = pDoc->InputImg[y][x];  //밝기 구하기
			hist[k]++; // 히스토그램에 밝기 입력
		}
	}
	//누적 분포 구하기
	acc_hist = 0;
	for (i = 0; i < 256; i++) {             //이것도 바꾸면 안된다
		acc_hist += hist[i];      //명암 누적값 추가하기
		sum[i] = acc_hist;        //명암 누적값 입력
	}

	//픽셀 밝기 변환
	for (y = 0; y < pDoc->ImageHeight; y++) {
		for (x = 0; x < pDoc->ImageWidth * pDoc->depth; x++) {
			k = pDoc->InputImg[y][x];//밝기 값 구하기
			pDoc->ResultImg[y][x] = (float)sum[k] / N * 255; //픽셀 히스토그램의 밝기 변환
		}
	}
	Invalidate();
}


void Cimageproc20210791View::OnPixelContrastStretchin()  //명암대비 스트래칭 스스로 작성해서 채워넣기
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	Cimageproc20210791Doc* pDoc = GetDocument();

	int x, y;
	int min = 0;
	int max = 0;
	for (y = 0; y < pDoc->ImageHeight; y++) {
		for (x = 0; x < pDoc->ImageWidth * pDoc->depth; x++) {
			if (max < pDoc->InputImg[y][x]) {   //max값 찾기
				max = pDoc->InputImg[y][x];
			}
			if (min > pDoc->InputImg[y][x])     //min값 찾기
				min = pDoc->InputImg[y][x];
		}
	}
	for (y = 0; y < pDoc->ImageHeight; y++) {                 //명암대비 스트래칭 구현하기
		for (x = 0; x < pDoc->ImageWidth * pDoc->depth; x++) {
			pDoc->ResultImg[y][x] = (pDoc->InputImg[y][x] - min) / (float(max - min)) * 255;
		}
	}

	Invalidate();
}


void Cimageproc20210791View::OnPixelBinaryization()  // 픽셀 2진화 처리
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	Cimageproc20210791Doc* pDoc = GetDocument();

	int threshold = 150;
	int x, y;
	for (y = 0; y < 256; y++) {
		for (x = 0; x < 256; x++) {
			if (pDoc->InputImg[y][x] >= threshold) {  //기존의 값을 정해진 T값과 비교
				pDoc->ResultImg[y][x] = 255;          //T값보다 크면 흰색이미지
			}
			else {
				pDoc->ResultImg[y][x] = 0;            //T값보다 작으면 검은색이미지
			}
		}
	}
	Invalidate();
}


void Cimageproc20210791View::OnPixelTowImageAdd()  // 두 영상을 합치는 함수
{
	Cimageproc20210791Doc* pDoc = GetDocument();
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	LoadTowImages();
	

	int x, y, value;
	for (y = 0; y < pDoc->ImageWidth; y++) {                 //명암대비 스트래칭 구현하기
		for (x = 0; x < pDoc->ImageHeight; x++) {
			value = 0.5 * pDoc->InputImg[y][x] + 0.5 * pDoc->InputImg2[y][x];  // 두 이미지를 정해진 비율대로 덧셈한다 0.0 숫자 비율
			if (value > 255) value = 255;
			else if (value < 0) value = 0;
			pDoc->ResultImg[y][x] = value;                         // 두 이미지를 덧셈한 결과를 전달
		}
	}

	Invalidate();
}


void Cimageproc20210791View::LoadTowImages()
{
	Cimageproc20210791Doc* pDoc = GetDocument();

	// TODO: 여기에 구현 코드 추가.       -----------   기존코드 ------------
	CFileDialog dlg(TRUE);                         //파일열기 다이얼로그 생성
                 
	if (dlg.DoModal() == IDOK) {                  //확인 버튼을 눌렀을 때 다이얼로그를 동작한다
		CFile file;                                      
		file.Open(dlg.GetPathName(), CFile::modeRead);    //파일을 열기
		CArchive ar(&file, CArchive::load);
		pDoc->LOadSecondImageFile(ar);		      
		
		file.Close();
	}

	/*CFile file;
	CFileDialog dlg(TRUE);

	AfxMessageBox("Select the First Images");
	if (dlg.DoModal() == IDOK) {
		file.Open(dlg.GetPathName(), CFile::modeRead);
		CArchive ar(&file, CArchive::load);
		pDoc->LoadImageFile(ar);
		file.Close();
	}*/
}


void Cimageproc20210791View::OnPixelTowImagesub()
{
	Cimageproc20210791Doc* pDoc = GetDocument();
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	LoadTowImages();
	int x, y, value;
	for (y = 0; y < pDoc->ImageHeight; y++) {                 //명암대비 스트래칭 구현하기 원래 기본값 255
		for (x = 0; x < pDoc->ImageWidth * pDoc->depth; x++) {
			value = pDoc->InputImg[y][x] - pDoc->InputImg2[y][x];  // 두 이미지를 뺄셈한다 
			if (value > 255) value = 255;
			else if (value < 0) value = 0;
			if (value > 64) {
				value = 255;
			}
			else {
				value = 0;
			}

			pDoc->ResultImg[y][x] = value;                         // 두 이미지를 뺄셈한 결과를 전달
		}
	}

	Invalidate();
}


void Cimageproc20210791View::OnRegionSharpening()    // 선명하게 하기 효과
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	Cimageproc20210791Doc* pDoc = GetDocument();

	float kernel[3][3] = { {0,-1,0} , {-1,5,-1}, {0,-1,0} };
	
	convolve(pDoc->InputImg, pDoc->ResultImg, pDoc->ImageWidth, pDoc->ImageHeight, kernel, 0, pDoc->depth);

	Invalidate();

}


void Cimageproc20210791View::convolve(unsigned char** inimg, unsigned char** outimg, int cols, int rows, float mask[][3], int bias, int depth)
{
	// TODO: 여기에 구현 코드 추가.   선명도를 반영하는 함수
	int x, y;
	int i, j;
	int sum, rsum, gsum, bsum;

	for (y = 1; y < rows -1; y++) {
		for (x = 1; x < cols -1; x++) {	
			
			if (depth == 1) {
				sum = 0;
				for (j = 0; j < 3; j++) {
					for (i = 0; i < 3; i++)
					{
						sum += (inimg[y + j - 1][x + i - 1] * mask[j][i]);
					}
				}
				sum += bias;
				if (sum > 255) sum = 255;
				else if (sum < 0) sum = 0;

				outimg[y][x] = sum;
			}
			else {
				rsum = 0;	gsum = 0;	bsum = 0;
				for (j = 0; j < 3; j++) {
					for (i = 0; i < 3; i++)
					{
						rsum += (inimg[y + j - 1][3 * (x + i - 1) + 0] * mask[j][i]);
						gsum += (inimg[y + j - 1][3 * (x + i - 1) + 1] * mask[j][i]);
						bsum += (inimg[y + j - 1][3 * (x + i - 1) + 2] * mask[j][i]);
					}
				}
				rsum += bias;
				gsum += bias;
				bsum += bias;

				if (rsum > 255) rsum = 255;
				else if (rsum < 0) rsum = 0;
				if (gsum > 255) gsum = 255;
				else if (gsum < 0) gsum = 0;
				if (bsum > 255) bsum = 255;
				else if (bsum < 0) bsum = 0;

				outimg[y][3 * x + 0] = rsum;
				outimg[y][3 * x + 1] = gsum;
				outimg[y][3 * x + 2] = bsum;
			}

		}
	}
}


void Cimageproc20210791View::OnResionSmoothing()  //흐리게 하기 효과
{
	Cimageproc20210791Doc* pDoc = GetDocument();

	float kernel[3][3] = { {0.1, 0.1, 0.1} , {0.1, 0.1, 0.1}, {0.1, 0.1, 0.1} }; //커널만 바꾸기

	convolve(pDoc->InputImg, pDoc->ResultImg, pDoc->ImageWidth, pDoc->ImageHeight, kernel, 0, pDoc->depth);

	Invalidate();
}


void Cimageproc20210791View::OnRegionEmbossing() // 엠보싱 효과 경계선 처리와 비슷하게 나온다
{
	Cimageproc20210791Doc* pDoc = GetDocument();

	float kernel[3][3] = { {-1,0,0} , {0,0,0}, {0,0,1} }; //커널만 바꾸기

	convolve(pDoc->InputImg, pDoc->ResultImg, pDoc->ImageWidth, pDoc->ImageHeight, kernel, 128, pDoc->depth);

	Invalidate();
}




/*
void Cimageproc20210791View::LoadImageFile(CArchive& ar)
{
	Cimageproc20210791Doc* pDoc = GetDocument();
	// TODO: 여기에 구현 코드 추가.
	int i, maxValue;
	CString type, buf;
	CFile* fp = ar.GetFile();
	CString fname = fp->GetFilePath();

	//파일의 헤더 읽기
	if (strcmp(strrchr(fname, '.'), ".ppm") == 0 ||
		strcmp(strrchr(fname, '.'), ".PPM") == 0 ||
		strcmp(strrchr(fname, '.'), ".PGM") == 0 ||
		strcmp(strrchr(fname, '.'), ".pgm") == 0) {
		ar.ReadString(type, 15);

		do {
			ar.ReadString(buf, 255);
		} while (buf[0] == '#');
		sscanf_s(buf, "%d %d", pDoc->ImageWidth, pDoc->ImageHeight);
		do {
			ar.ReadString(buf, 255);
		} while (buf[0] == '#');
		sscanf_s(buf, "%d", &maxValue);

		if (strcmp(type, "P5") == 0) pDoc->depth = 1;
		else  pDoc->depth = 3;
	}
	else if (strcmp(strrchr(fname, '.'), ".raw") == 0 ||
		strcmp(strrchr(fname, '.'), ".RAW") == 0)
	{
		if (fp->GetLength() != 256 * 256) {
			AfxMessageBox("256x256 크기의 파일만 사용가능합니다.");
			return;
		}

		pDoc->ImageWidth = 256;
		pDoc->ImageHeight = 256;
		pDoc->depth = 1;
	}

	// 기억장소 할당
	pDoc->InputImg2 = (unsigned char**)malloc(pDoc->ImageHeight * sizeof(unsigned char*));

	for (i = 0; i < pDoc->ImageHeight; i++) {
		pDoc->InputImg2[i] = (unsigned char*)malloc(pDoc->ImageWidth * pDoc->depth);
	}

	// 영상 데이터 읽기 
	for (i = 0; i < pDoc->ImageHeight; i++)
		ar.Read(pDoc->InputImg2[i], pDoc->ImageWidth * pDoc->depth); {
	}
}
*/

void Cimageproc20210791View::OnRegionPrewitt()           //칼라 영상도 경계선 검출이 되도록 만들어야 한다.
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.

	Cimageproc20210791Doc* pDoc = GetDocument();

	float kernel_h[3][3] = { {-1,-1,-1} , {0, 0, 0}, {1,1,1} }; //커널만 바꾸기
	float kernel_v[3][3] = { {-1, 0, 1} , {-1, 0, 1}, {-1, 0, 1} };

	unsigned char** Er, ** Ec;
	//Er, Ec 메모리 할당

	int x, y,i;
	int value, rvalue,gvalue,bvalue;

	Er = (unsigned char**)malloc(pDoc->ImageHeight * sizeof(unsigned char*));
	Ec = (unsigned char**)malloc(pDoc->ImageHeight * sizeof(unsigned char*));

	for (i = 0; i < pDoc->ImageHeight; i++) {
		Er[i] = (unsigned char*)malloc(pDoc->ImageWidth * pDoc->depth);
		Ec[i] = (unsigned char*)malloc(pDoc->ImageWidth * pDoc->depth);
	}

	convolve(pDoc->InputImg, Er, pDoc->ImageWidth, pDoc->ImageHeight, kernel_h, 128, pDoc->depth);
	convolve(pDoc->InputImg, Ec, pDoc->ImageWidth, pDoc->ImageHeight, kernel_v, 128, pDoc->depth);

	for (y = 0; y < pDoc->ImageHeight; y++) {                 //명암대비 스트래칭 구현하기 원래 기본값 255
		for (x = 0; x < pDoc->ImageWidth; x++) {
			if (pDoc->depth == 1) {
				value = sqrt((Er[y][x] - 128) * (Er[y][x] - 128) + (Ec[y][x] - 128) * (Ec[y][x] - 128));
				if (value > 255) value = 255;
				else if (value < 0) value = 0;
				pDoc->ResultImg[y][x] = value;

			}
			else {
				rvalue = sqrt((Er[y][3 * x + 0] - 128) * (Er[y][3 * x + 0] - 128) + (Ec[y][3 * x + 0] - 128) * (Ec[y][3 * x + 0] - 128));
				gvalue = sqrt((Er[y][3 * x + 1] - 128) * (Er[y][3 * x + 1] - 128) + (Ec[y][3 * x + 1] - 128) * (Ec[y][3 * x + 1] - 128));
				bvalue = sqrt((Er[y][3 * x + 2] - 128) * (Er[y][3 * x + 2] - 128) + (Ec[y][3 * x + 2] - 128) * (Ec[y][3 * x + 2] - 128));

				value = sqrt(rvalue * rvalue + gvalue * gvalue + bvalue * bvalue);  // RGB값을 모아서 합치는 부분

				if (value > 255) value = 255;         //영역검사하는 부분
				else if (value < 0) value = 0;
				pDoc->ResultImg[y][3 * x + 0] = value;
				pDoc->ResultImg[y][3 * x + 1] = value;
				pDoc->ResultImg[y][3 * x + 2] = value;
			}

		}
	}

	// 만들었던 메모리를 사용후 삭제
	for (i = 0; i < pDoc->ImageHeight; i++) {
		free(Er[i]);
		free(Ec[i]);
	}
	free(Er); free(Ec);
	Invalidate();
}


void Cimageproc20210791View::OnRegionRoberth()    // 각자 만들기---------------------------------------------- 만듬
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	Cimageproc20210791Doc* pDoc = GetDocument();

	float kernel_h[3][3] = { {-1 , 0, 0} , {0, 1, 0}, {0, 0, 0} }; //커널만 바꾸기
	float kernel_v[3][3] = { {0, 0, -1} , {0, 1, 0}, {0, 0, 0} };

	unsigned char** Er, ** Ec;
	//Er, Ec 메모리 할당

	int x, y, i;
	int value, rvalue, gvalue, bvalue;

	Er = (unsigned char**)malloc(pDoc->ImageHeight * sizeof(unsigned char*));
	Ec = (unsigned char**)malloc(pDoc->ImageHeight * sizeof(unsigned char*));

	for (i = 0; i < pDoc->ImageHeight; i++) {
		Er[i] = (unsigned char*)malloc(pDoc->ImageWidth * pDoc->depth);
		Ec[i] = (unsigned char*)malloc(pDoc->ImageWidth * pDoc->depth);
	}

	convolve(pDoc->InputImg, Er, pDoc->ImageWidth, pDoc->ImageHeight, kernel_h, 128, pDoc->depth);
	convolve(pDoc->InputImg, Ec, pDoc->ImageWidth, pDoc->ImageHeight, kernel_v, 128, pDoc->depth);

	for (y = 0; y < pDoc->ImageHeight; y++) {                 //명암대비 스트래칭 구현하기 원래 기본값 255
		for (x = 0; x < pDoc->ImageWidth; x++) {
			if (pDoc->depth == 1) {
				value = sqrt((Er[y][x] - 128) * (Er[y][x] - 128) + (Ec[y][x] - 128) * (Ec[y][x] - 128));
				if (value > 255) value = 255;
				else if (value < 0) value = 0;
				pDoc->ResultImg[y][x] = value;

			}
			else {
				rvalue = sqrt((Er[y][3 * x + 0] - 128) * (Er[y][3 * x + 0] - 128) + (Ec[y][3 * x + 0] - 128) * (Ec[y][3 * x + 0] - 128));
				gvalue = sqrt((Er[y][3 * x + 1] - 128) * (Er[y][3 * x + 1] - 128) + (Ec[y][3 * x + 1] - 128) * (Ec[y][3 * x + 1] - 128));
				bvalue = sqrt((Er[y][3 * x + 2] - 128) * (Er[y][3 * x + 2] - 128) + (Ec[y][3 * x + 2] - 128) * (Ec[y][3 * x + 2] - 128));

				value = sqrt(rvalue * rvalue + gvalue * gvalue + bvalue * bvalue);  // RGB값을 모아서 합치는 부분

				if (value > 255) value = 255;         //영역검사하는 부분
				else if (value < 0) value = 0;
				pDoc->ResultImg[y][3 * x + 0] = value;
				pDoc->ResultImg[y][3 * x + 1] = value;
				pDoc->ResultImg[y][3 * x + 2] = value;
			}

		}
	}

	// 만들었던 메모리를 사용후 삭제
	for (i = 0; i < pDoc->ImageHeight; i++) {
		free(Er[i]);
		free(Ec[i]);
	}
	free(Er); free(Ec);
	Invalidate();
}


void Cimageproc20210791View::OnRegionSobel()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	Cimageproc20210791Doc* pDoc = GetDocument();

	float kernel_h[3][3] = { {1 ,-2, -1} , {0, 0, 0}, {1, 2, 1} }; //커널만 바꾸기
	float kernel_v[3][3] = { {1, 0, -1} , {2, 0, -2}, {1, 0, -1} };

	unsigned char** Er, ** Ec;
	//Er, Ec 메모리 할당

	int x, y, i;
	int value, rvalue, gvalue, bvalue;

	Er = (unsigned char**)malloc(pDoc->ImageHeight * sizeof(unsigned char*));
	Ec = (unsigned char**)malloc(pDoc->ImageHeight * sizeof(unsigned char*));

	for (i = 0; i < pDoc->ImageHeight; i++) {
		Er[i] = (unsigned char*)malloc(pDoc->ImageWidth * pDoc->depth);
		Ec[i] = (unsigned char*)malloc(pDoc->ImageWidth * pDoc->depth);
	}

	convolve(pDoc->InputImg, Er, pDoc->ImageWidth, pDoc->ImageHeight, kernel_h, 128, pDoc->depth);
	convolve(pDoc->InputImg, Ec, pDoc->ImageWidth, pDoc->ImageHeight, kernel_v, 128, pDoc->depth);

	for (y = 0; y < pDoc->ImageHeight; y++) {                 //명암대비 스트래칭 구현하기 원래 기본값 255
		for (x = 0; x < pDoc->ImageWidth; x++) {
			if (pDoc->depth == 1) {
				value = sqrt((Er[y][x] - 128) * (Er[y][x] - 128) + (Ec[y][x] - 128) * (Ec[y][x] - 128));
				if (value > 255) value = 255;
				else if (value < 0) value = 0;
				pDoc->ResultImg[y][x] = value;

			}
			else {
				rvalue = sqrt((Er[y][3 * x + 0] - 128) * (Er[y][3 * x + 0] - 128) + (Ec[y][3 * x + 0] - 128) * (Ec[y][3 * x + 0] - 128));
				gvalue = sqrt((Er[y][3 * x + 1] - 128) * (Er[y][3 * x + 1] - 128) + (Ec[y][3 * x + 1] - 128) * (Ec[y][3 * x + 1] - 128));
				bvalue = sqrt((Er[y][3 * x + 2] - 128) * (Er[y][3 * x + 2] - 128) + (Ec[y][3 * x + 2] - 128) * (Ec[y][3 * x + 2] - 128));

				value = sqrt(rvalue * rvalue + gvalue * gvalue + bvalue * bvalue);  // RGB값을 모아서 합치는 부분

				if (value > 255) value = 255;         //영역검사하는 부분
				else if (value < 0) value = 0;
				pDoc->ResultImg[y][3 * x + 0] = value;
				pDoc->ResultImg[y][3 * x + 1] = value;
				pDoc->ResultImg[y][3 * x + 2] = value;
			}

		}
	}

	// 만들었던 메모리를 사용후 삭제
	for (i = 0; i < pDoc->ImageHeight; i++) {
		free(Er[i]);
		free(Ec[i]);
	}
	free(Er); free(Ec);
	Invalidate();
}


void Cimageproc20210791View::OnRegionAverageFiltering()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	Cimageproc20210791Doc* pDoc = GetDocument();

	int x, y,i,j;
	int xpos, ypos;
	int sum,rsum,gsum,bsum;
	int pixelCount;

	for (y = 0; y < pDoc->ImageHeight; y++) {
		for (x = 0; x < pDoc->ImageWidth; x++) {
			sum = 0; pixelCount = 0; rsum = gsum = bsum = 0;

			for (j = -2; j <= 2; j++) {   //픽셀 갯수 구하기
				for (i = -2; i <= 2; i++) {
					xpos = x + i;
					ypos = y + j;

					if (xpos >= 0 && xpos <= pDoc->ImageWidth - 1 && ypos >= 0 && ypos <= pDoc->ImageHeight - 1) {
						if (pDoc->depth == 1) {
							sum += pDoc->InputImg[y + j][x + i];
						}
						else {
							rsum += pDoc->InputImg[y + j][3 * (x + i) + 0];
							gsum += pDoc->InputImg[y + j][3 * (x + i) + 1];
							bsum += pDoc->InputImg[y + j][3 * (x + i) + 2];
						}
						pixelCount++;
					}
					
				}
			}
			if (pDoc->depth == 1) {
				pDoc->ResultImg[y][x] = sum / pixelCount;
			}
			else {
				pDoc->ResultImg[y][3 * x + 0] = rsum / pixelCount;
				pDoc->ResultImg[y][3 * x + 1] = gsum / pixelCount;
				pDoc->ResultImg[y][3 * x + 2] = bsum / pixelCount;
			}
		}
	}
	Invalidate();
}


void Cimageproc20210791View::OnRegionMedianFiletering()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	Cimageproc20210791Doc* pDoc = GetDocument();
	int x, y,i,j;
	int n[9], temp;

	for (y = 1; y < pDoc->ImageHeight-1; y++) {
		for (x = 1; x < pDoc->ImageWidth-1; x++) {
			n[0] = pDoc->InputImg[y - 1][x - 1];
			n[1] = pDoc->InputImg[y - 1][x - 0];
			n[2] = pDoc->InputImg[y - 1][x + 1];
			n[3] = pDoc->InputImg[y - 0][x - 1];
			n[4] = pDoc->InputImg[y - 0][x - 0];
			n[5] = pDoc->InputImg[y - 0][x + 1];
			n[6] = pDoc->InputImg[y + 1][x - 1];
			n[7] = pDoc->InputImg[y + 1][x - 0];
			n[8] = pDoc->InputImg[y + 1][x + 1];
			
			//버블 소팅(오름차순)
			for (i = 8; i > 0; i--) {
				for (j = 0; j < i; j++) {
					if (n[j] > n[j + 1]) {
						n[j + 1] = n[j];
						n[j] = temp;
					}
				}
			}
			pDoc->ResultImg[y][x] = n[4];
		}

	}
	Invalidate();
}


void Cimageproc20210791View::OnMopologyColorToGray()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	Cimageproc20210791Doc* pDoc = GetDocument();
	if (pDoc->depth == 1) return;
	int x, y;
	int gray;

	for (y = 0; y < pDoc->ImageHeight; y++) {
		for (x = 0; x < pDoc->ImageWidth; x++) {
			gray = (pDoc->InputImg[y][3 * x + 0] + pDoc->InputImg[y][3 * x + 1] + pDoc->InputImg[y][3 * x + 2]) / 3;
			pDoc->InputImg[y][3 * x + 0] = gray;
			pDoc->InputImg[y][3 * x + 1] = gray;
			pDoc->InputImg[y][3 * x + 2] = gray;
		}
	}
	Invalidate();
}


void Cimageproc20210791View::OnMopologyBinarization()
{
	Cimageproc20210791Doc* pDoc = GetDocument();

	int x, y;
	int gray, threshold = 100;

	for (y = 0; y < pDoc->ImageHeight; y++) {
		for (x = 0; x < pDoc->ImageWidth; x++) {
			if (pDoc->depth == 1) {
				if (pDoc->InputImg[y][x] > threshold) pDoc->InputImg[y][x] = 255;
				else { pDoc->InputImg[y][x] = 0; }
			}
			else {
				if (pDoc->InputImg[y][3 * x + 0] + pDoc->InputImg[y][3 * x + 1] + pDoc->InputImg[y][3 * x + 2] / 3 > threshold) {
					pDoc->InputImg[y][3 * x + 0] = 255;
					pDoc->InputImg[y][3 * x + 1] = 255;
					pDoc->InputImg[y][3 * x + 2] = 255;

				}
				else {
					pDoc->InputImg[y][3 * x + 0] = 0;
					pDoc->InputImg[y][3 * x + 1] = 0;
					pDoc->InputImg[y][3 * x + 2] = 0;
				}
			}
		}
	}
	Invalidate();
}


void Cimageproc20210791View::OnMopologyErosion()
{
	Cimageproc20210791Doc* pDoc = GetDocument();
	int x, y, i, j;
	int min = 255, rmin,gmin,bmin;

	for (y = 1; y < pDoc->ImageHeight -1; y++) {
		for (x = 1; x < pDoc->ImageWidth -1; x++) {
			
			min = 255; rmin = 255; gmin = 255; bmin = 255;
			for (j = -1; j <= 1; j++) {
				for (i = -1; i <= 1; i++) {
					if (pDoc->depth == 1) {
						if (pDoc->InputImg[y + j][x + i] < min)
							min = pDoc->InputImg[y + j][x + i];
					}
					else {
						if (pDoc->InputImg[y + j][3 * (x + i) + 0] < rmin)	rmin = pDoc->InputImg[y + j][3 * (x + i) + 0];
						if (pDoc->InputImg[y + j][3 * (x + i) + 1] < gmin)	gmin = pDoc->InputImg[y + j][3 * (x + i) + 1];
						if (pDoc->InputImg[y + j][3 * (x + i) + 2] < bmin)	bmin = pDoc->InputImg[y + j][3 * (x + i) + 2];
					}
					
				}
			}
			if (pDoc->depth == 1) {
				pDoc->ResultImg[y][x] = min;
			}
			else {
				pDoc->ResultImg[y][3 * x + 0] = rmin;
				pDoc->ResultImg[y][3 * x + 1] = gmin;
				pDoc->ResultImg[y][3 * x + 2] = bmin;
			}
		}
	}
	Invalidate();
}


void Cimageproc20210791View::OnMopologyDilation()
{
	Cimageproc20210791Doc* pDoc = GetDocument();
	int x, y, i, j;
	int max , rmax, gmax, bmax;

	for (y = 1; y < pDoc->ImageHeight - 1; y++) {
		for (x = 1; x < pDoc->ImageWidth - 1; x++) {

			max = 0; rmax = 0; gmax = 0; bmax = 0;
			for (j = -1; j <= 1; j++) {
				for (i = -1; i <= 1; i++) {
					if (pDoc->depth == 1) {
						if (pDoc->InputImg[y + j][x + i] > max)
							max = pDoc->InputImg[y + j][x + i];
					}
					else {
						if (pDoc->InputImg[y + j][3 * (x + i) + 0] > rmax)	rmax = pDoc->InputImg[y + j][3 * (x + i) + 0];
						if (pDoc->InputImg[y + j][3 * (x + i) + 1] > gmax)	gmax = pDoc->InputImg[y + j][3 * (x + i) + 1];
						if (pDoc->InputImg[y + j][3 * (x + i) + 2] > bmax)	bmax = pDoc->InputImg[y + j][3 * (x + i) + 2];
					}

				}
			}
			if (pDoc->depth == 1) {
				pDoc->ResultImg[y][x] = max;
			}
			else {
				pDoc->ResultImg[y][3 * x + 0] = rmax;
				pDoc->ResultImg[y][3 * x + 1] = gmax;
				pDoc->ResultImg[y][3 * x + 2] = bmax;
			}
		}
	}
	Invalidate();
}


void Cimageproc20210791View::CopyResultInput()
{
	Cimageproc20210791Doc* pDoc = GetDocument();
	int x, y;

	for (y = 0; y < pDoc->ImageHeight; y++) {
		for (x = 0; x < pDoc->ImageWidth*pDoc->depth; x++) {
			pDoc->InputImg[y][x] = pDoc->ResultImg[y][x];
		}
	}

}


void Cimageproc20210791View::OnOnmopologyopening()
{
	OnMopologyErosion();
	CopyResultInput();
	OnMopologyErosion();
	CopyResultInput();
	OnMopologyErosion();
	CopyResultInput();

	OnMopologyDilation();
	CopyResultInput();
	OnMopologyDilation();
	CopyResultInput();
	OnMopologyDilation();
	CopyResultInput();

}
void Cimageproc20210791View::OnOnmopologyclosing()
{
	OnMopologyDilation();
	CopyResultInput();
	OnMopologyDilation();
	CopyResultInput();
	OnMopologyDilation();
	CopyResultInput();

	OnMopologyErosion();
	CopyResultInput();
	OnMopologyErosion();
	CopyResultInput();
	OnMopologyErosion();
	CopyResultInput();
}


void Cimageproc20210791View::OnGeometryZoominPixelCopy()
{
	Cimageproc20210791Doc* pDoc = GetDocument();
	int x, y, i;

	int xscale = 3;
	int yscale = 2;

	//메모리 초기화
	if (pDoc->gResultImg != NULL) {
		for (i = 0; i < pDoc->gImageHeight; i++) {
			free(pDoc->gResultImg[i]);
		}
		free(pDoc->gResultImg);
	}

	pDoc->gImageWidth = pDoc->ImageWidth * xscale;
	pDoc->gImageHeight = pDoc->ImageHeight * yscale;
	//메모리 할당
	pDoc->gResultImg = (unsigned char**)malloc(pDoc->gImageHeight * sizeof(unsigned char*));

	for (i = 0; i < pDoc->gImageHeight; i++) {
		pDoc->gResultImg[i] = (unsigned char*)malloc(pDoc->gImageWidth * pDoc->depth);
	}
/*
	//전방향 사상 처리방법
	for (y = 0; y < pDoc->ImageHeight; y++) {
		for (x = 0; x < pDoc->ImageWidth; x++) {
			
			pDoc->gResultImg[y * yscale][x * yscale] = pDoc->InputImg[y][x];					//흑백
		}
	}
*/
	//역방향 사상 처리방법                            가능하면 정방향보다 역방향으로 프로그래밍하자
	for (y = 0; y < pDoc->gImageHeight; y++) {
		for (x = 0; x < pDoc->gImageWidth; x++) {
			if(pDoc->depth == 1)
				pDoc->gResultImg[y][x] = pDoc->InputImg[y / yscale][x / xscale];					//흑백
			else {																					//칼라
				pDoc->gResultImg[y][3 * x + 0] = pDoc->InputImg[y / yscale][3 * (x / xscale) + 0];
				pDoc->gResultImg[y][3 * x + 1] = pDoc->InputImg[y / yscale][3 * (x / xscale) + 1];
				pDoc->gResultImg[y][3 * x + 2] = pDoc->InputImg[y / yscale][3 * (x / xscale) + 2];
			}
		}
	}
	Invalidate();
}


void Cimageproc20210791View::OnGeometryZoominBilinearIntetpolation()
{
	Cimageproc20210791Doc* pDoc = GetDocument();
	int x, y, i;

	float xscale = 2.1;
	float yscale = 1.5;
	float src_x, src_y;
	float alpha, beta;
	int Ax, Ay, Bx, By, Cx, Cy, Dx, Dy;
	int E, F;

	//메모리 초기화
	if (pDoc->gResultImg != NULL) {
		for (i = 0; i < pDoc->gImageHeight; i++) {
			free(pDoc->gResultImg[i]);
		}
		free(pDoc->gResultImg);
	}

	pDoc->gImageWidth = (pDoc->ImageWidth) * xscale;
	pDoc->gImageHeight = (pDoc->ImageHeight) * yscale; //+ 0.5는 반올림할때 사용
	//메모리 할당
	pDoc->gResultImg = (unsigned char**)malloc(pDoc->gImageHeight * sizeof(unsigned char*));

	for (i = 0; i < pDoc->gImageHeight; i++) {
		pDoc->gResultImg[i] = (unsigned char*)malloc(pDoc->gImageWidth * pDoc->depth);
	}
	
	//역방향 사상 처리방법
	for (y = 0; y < pDoc->gImageHeight; y++) {
		for (x = 0; x < pDoc->gImageWidth; x++) {
			src_x = x / xscale;
			src_y = y / yscale;
			alpha = src_x - (int)src_x;  //소숫점 아랫값 전달
			beta = src_y - (int)src_y;

			Ax = (int)src_x;	//정수값 전달
			Ay = (int)src_y;
			Bx = Ax + 1;
			By = Ay;
			Cx = Ax;
			Cy = Ay + 1;
			Dx = Ax + 1;
			Dy = Ay + 1;

			if (Bx > pDoc->ImageWidth - 1) Bx = pDoc->ImageWidth - 1;         //범위 밖으로 나가지 않게 막아둠
			if (Cy > pDoc->ImageHeight - 1) Cy = pDoc->ImageHeight - 1;
			if (Dx > pDoc->ImageWidth - 1) Dx = pDoc->ImageWidth - 1;
			if (Dy > pDoc->ImageHeight - 1) Dy = pDoc->ImageHeight - 1;

			if (pDoc->depth == 1) {
				E = (1 - alpha) * pDoc->InputImg[Ay][Ax] + alpha * pDoc->InputImg[By][Bx];
				F = (1 - alpha) * pDoc->InputImg[Cy][Cx] + alpha * pDoc->InputImg[Dy][Dx];

				pDoc->gResultImg[y][x] = (1 - beta) * E + beta * F;
			}
			else {
				E = (1 - alpha) * pDoc->InputImg[Ay][3 * Ax + 0] + alpha * pDoc->InputImg[By][3* Bx + 0];
				F = (1 - alpha) * pDoc->InputImg[Cy][3 * Cx + 0] + alpha * pDoc->InputImg[Dy][3 * Dx + 0];
				pDoc->gResultImg[y][3 * x + 0] = (1 - beta) * E + beta * F;

				E = (1 - alpha) * pDoc->InputImg[Ay][3 * Ax + 1] + alpha * pDoc->InputImg[By][3 * Bx + 1];
				F = (1 - alpha) * pDoc->InputImg[Cy][3 * Cx + 1] + alpha * pDoc->InputImg[Dy][3 * Dx + 1];
				pDoc->gResultImg[y][3 * x + 1] = (1 - beta) * E + beta * F;

				E = (1 - alpha) * pDoc->InputImg[Ay][3 * Ax + 2] + alpha * pDoc->InputImg[By][3 * Bx + 2];
				F = (1 - alpha) * pDoc->InputImg[Cy][3 * Cx + 2] + alpha * pDoc->InputImg[Dy][3 * Dx + 2];
				pDoc->gResultImg[y][3 * x + 2] = (1 - beta) * E + beta * F;
			}
			
		}
	}
	Invalidate();
}


void Cimageproc20210791View::OnGeometryZoomoutSubsampling()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	Cimageproc20210791Doc* pDoc = GetDocument();

	int x, y, i;
	int xscale = 3;    // 3분에 1로 축소
	int yscale = 2;    // 2분에 1로 축소

	if (pDoc->gResultImg != NULL) {
		for (i = 0; i < pDoc->gImageHeight; i++) {
			free(pDoc->gResultImg[i]);
		}
		free(pDoc->gResultImg);
	}


	pDoc->gImageWidth = (pDoc->ImageWidth) / xscale;
	pDoc->gImageHeight = (pDoc->ImageHeight) / yscale;
	//메모리 할당
	pDoc->gResultImg = (unsigned char**)malloc(pDoc->gImageHeight * sizeof(unsigned char*));

	for (i = 0; i < pDoc->gImageHeight; i++) {
		pDoc->gResultImg[i] = (unsigned char*)malloc(pDoc->gImageWidth * pDoc->depth);
	}

	//역방향 사상 처리방법
	for (y = 0; y < pDoc->gImageHeight; y++) {
		for (x = 0; x < pDoc->gImageWidth; x++) {
			if (pDoc->depth == 1) {
				pDoc->gResultImg[y][x] = pDoc->InputImg[y * yscale][x * xscale];
			}
			else {
				pDoc->gResultImg[y][3 * x + 0] = pDoc->InputImg[y * yscale][3 * (x * xscale) + 0];
				pDoc->gResultImg[y][3 * x + 1] = pDoc->InputImg[y * yscale][3 * (x * xscale) + 1];
				pDoc->gResultImg[y][3 * x + 2] = pDoc->InputImg[y * yscale][3 * (x * xscale) + 2];
			}
		}
	}

	Invalidate();
}


void Cimageproc20210791View::OnGeometryZoomoutMeanSub()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	OnResionSmoothing();
	CopyResultInput();
	OnGeometryZoomoutSubsampling();
}


void Cimageproc20210791View::OnGeometryAvgSampling()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	Cimageproc20210791Doc* pDoc = GetDocument();

	int x, y, i,j;
	int xscale = 3;    // 3분에 1로 축소
	int yscale = 2;    // 2분에 1로 축소
	int src_x, src_y;
	int sum, rsum, gsum, bsum;

	if (pDoc->gResultImg != NULL) {
		for (i = 0; i < pDoc->gImageHeight; i++) {
			free(pDoc->gResultImg[i]);
		}
		free(pDoc->gResultImg);
	}


	pDoc->gImageWidth = (pDoc->ImageWidth) / xscale;
	pDoc->gImageHeight = (pDoc->ImageHeight) / yscale;
	//메모리 할당
	pDoc->gResultImg = (unsigned char**)malloc(pDoc->gImageHeight * sizeof(unsigned char*));

	for (i = 0; i < pDoc->gImageHeight; i++) {
		pDoc->gResultImg[i] = (unsigned char*)malloc(pDoc->gImageWidth * pDoc->depth);
	}

	//정방향 사상 처리방법
	for (y = 0; y < pDoc->ImageHeight; y+= yscale) {
		for (x = 0; x < pDoc->ImageWidth; x+=xscale) {
			
			sum = 0;
			rsum = 0; gsum = 0; bsum = 0;
			for (j = 0; j < yscale; j++) {
				for (i = 0; i < xscale; i++) {
					src_x = x + i;
					src_y = y + j;
					if (src_x > pDoc->ImageWidth - 1) src_x = pDoc->ImageWidth - 1;
					if (src_y > pDoc->ImageHeight - 1) src_y = pDoc->ImageHeight - 1;
					
					if (pDoc->depth == 1) {
						sum += pDoc->InputImg[src_y][src_x];
					}
					else {
						rsum += pDoc->InputImg[src_y][3 * src_x + 0];
						gsum += pDoc->InputImg[src_y][3 * src_x + 1];
						bsum += pDoc->InputImg[src_y][3 * src_x + 2];
					}
				}
			}
			if (pDoc->depth == 1) {
				pDoc->gResultImg[y / yscale][x / xscale] = sum / (xscale * yscale);
			}
			else {
				pDoc->gResultImg[y / yscale][3 * (x / xscale) + 0] = rsum / (xscale * yscale);
				pDoc->gResultImg[y / yscale][3 * (x / xscale) + 1] = gsum / (xscale * yscale);
				pDoc->gResultImg[y / yscale][3 * (x / xscale) + 2] = bsum / (xscale * yscale);
			}
			
		
		}
	}

	Invalidate();
}
