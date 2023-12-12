
// imageproc_20210791Doc.cpp: Cimageproc20210791Doc 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "imageproc_20210791.h"
#endif

#include "imageproc_20210791Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// Cimageproc20210791Doc

IMPLEMENT_DYNCREATE(Cimageproc20210791Doc, CDocument)

BEGIN_MESSAGE_MAP(Cimageproc20210791Doc, CDocument)
END_MESSAGE_MAP()


// Cimageproc20210791Doc 생성/소멸

Cimageproc20210791Doc::Cimageproc20210791Doc() noexcept	
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

	InputImg = NULL;
	InputImg2 = NULL;
	ResultImg = NULL;

	gResultImg = NULL;

}

Cimageproc20210791Doc::~Cimageproc20210791Doc()
{
	int i;
	if (InputImg != NULL) {
		for (i = 0; i < ImageHeight; i++) {
			free(InputImg[i]);
		}
		free(InputImg);
	}
	if (InputImg2 != NULL) {
		for (i = 0; i < ImageHeight; i++) {
			free(InputImg2[i]);
		}
		free(InputImg2);
	}
	if (ResultImg != NULL) {
		for (i = 0; i < ImageHeight; i++) {
			free(ResultImg[i]);
		}
		free(ResultImg);
	}
	if (gResultImg != NULL) {
		for (i = 0; i < gImageHeight; i++) {
			free(gResultImg[i]);
		}
		free(gResultImg);
	}
}

BOOL Cimageproc20210791Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// Cimageproc20210791Doc serialization

void Cimageproc20210791Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 여기에 저장 코드를 추가합니다.
	}
	else
	{
		LoadImageFile(ar);
	}
}

#ifdef SHARED_HANDLERS

// 축소판 그림을 지원합니다.
void Cimageproc20210791Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 문서의 데이터를 그리려면 이 코드를 수정하십시오.
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 검색 처리기를 지원합니다.
void Cimageproc20210791Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// 문서의 데이터에서 검색 콘텐츠를 설정합니다.
	// 콘텐츠 부분은 ";"로 구분되어야 합니다.

	// 예: strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void Cimageproc20210791Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// Cimageproc20210791Doc 진단

#ifdef _DEBUG
void Cimageproc20210791Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void Cimageproc20210791Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// Cimageproc20210791Doc 명령


void Cimageproc20210791Doc::LoadImageFile(CArchive& ar)
{
	// TODO: 여기에 구현 코드 추가.

	CFile* fp = ar.GetFile();
	CString fname = fp->GetFilePath();  //파일 이름 읽어오기
	char type[16], buf[256];
	int MaxValue, i;
	bool isbmp = false;

	if (strcmp(strchr(fname, '.'), ".ppm") == 0 || strcmp(strchr(fname, '.'), ".PPM") == 0 ||
		strcmp(strchr(fname, '.'), ".pgm") == 0 || strcmp(strchr(fname, '.'), ".PGM") == 0) {
		ar.ReadString(type, 15);  // p5 등이 읽어진다.
		do {
			ar.ReadString(buf, 255);   // 그림의 높이 길이가 구해진다
		} while (buf[0] == '#');
		
		sscanf_s(buf, "%d %d", &ImageWidth, &ImageHeight);
		
		do {
			ar.ReadString(buf, 255);   // 색상이 구해진다
		} while (buf[0] == '#');
		sscanf_s(buf, "%d ", &MaxValue);

		if (strcmp(type, "P5") == 0) {  //칼라인지 흑백인지
			depth = 1;   //흑백
		}
		else {
			depth = 3;  //칼라
		}
	}
	else if (strcmp(strchr(fname, '.'), ".bmp") == 0 || strcmp(strchr(fname, '.'), ".BMP") == 0) {
		//bitmap file header 읽기
		BITMAPFILEHEADER bmfh;
		ar.Read((LPSTR)&bmfh, sizeof(bmfh));
		//bmp 화일임을 나타내는 "BM"마커가 있는지 확인
		if (bmfh.bfType != (WORD)(('M' << 8) | 'B')) return;

		//bitmap info header 읽기
		BITMAPINFOHEADER bih;
		ar.Read((LPSTR)&bih, sizeof(bih));
		ImageWidth = bih.biWidth;
		ImageHeight = bih.biHeight;
		depth = bih.biBitCount / 8;

		//palette 처리
		if (depth == 1) {
			// palette 존재
			BYTE palette[256 * 4];
			ar.Read(palette, 256 * 4);
		}
		isbmp = true;
	}
	else if (strcmp(strchr(fname, '.'), ".raw") == 0 || strcmp(strchr(fname, '.'), ".RAW") == 0) {
		if (fp->GetLength() != 256 * 256) {
			AfxMessageBox("256 * 256 크기의 raw파일만 읽을 수 있습니다.");
			return;
		}
		ImageWidth = 256; ImageHeight = 256; 
		depth = 1;
	}
	
	//메모리 할당 하는 부분

	InputImg = (unsigned char**)malloc(ImageHeight * sizeof(unsigned char*));
	ResultImg = (unsigned char**)malloc(ImageHeight * sizeof(unsigned char*));

	for (int i = 0; i < ImageHeight; i++) {
		InputImg[i] = (unsigned char*) malloc(ImageWidth * depth);
		ResultImg[i] = (unsigned char*) malloc(ImageWidth * depth);
	}

	if(!isbmp){
		// 영상 데이터 읽기

		for (int i = 0; i < ImageHeight; i++) {
			ar.Read(InputImg[i], ImageWidth * depth);
		}
	}
	else {
		// BMP영상 데이터 읽기
		BYTE nu[4*3];
		int widthfile;
		widthfile = (ImageWidth * 8 + 31) / 32 * 4;
		for (int i = 0; i < ImageHeight; i++) {
	
			if (depth == 1) {
				ar.Read(InputImg[ImageHeight - 1 - i], ImageWidth * depth);
			}
			else {
				// BGR => RGB
				BYTE r, g, b;
				for (int j = 0; j < ImageWidth; j++) {
					ar.Read(&b, 1); ar.Read(&g, 1); ar.Read(&r, 1);
					InputImg[ImageHeight - 1 - i][3 * j + 0] = r;
					InputImg[ImageHeight - 1 - i][3 * j + 1] = g;
					InputImg[ImageHeight - 1 - i][3 * j + 2] = b;
				}
			}
		
			if ((widthfile - ImageWidth) != 0) {
				ar.Read(nu, (widthfile - ImageWidth) * depth);
			}
		}
	}
	
}


void Cimageproc20210791Doc::LOadSecondImageFile(CArchive& ar)
{
	// TODO: 여기에 구현 코드 추가.
	CFile* fp = ar.GetFile();
	CString fname = fp->GetFilePath();  //파일 이름 읽어오기
	char type[16], buf[256];
	int MaxValue;
	int temp_w, temp_h, temp_depth;
	bool isbmp = false;


	if (strcmp(strchr(fname, '.'), ".ppm") == 0 || strcmp(strchr(fname, '.'), ".PPM") == 0 ||
		strcmp(strchr(fname, '.'), ".pgm") == 0 || strcmp(strchr(fname, '.'), ".PGM") == 0) {
		ar.ReadString(type, 15);  // p5 등이 읽어진다.
		do {
			ar.ReadString(buf, 256);   // 그림의 높이 길이가 구해진다
		} while (buf[0] == '#');

		sscanf_s(buf, "%d %d", &temp_w, &temp_h);

		do {
			ar.ReadString(buf, 256);   // 색상이 구해진다
		} while (buf[0] == '#');
		sscanf_s(buf, "%d ", &MaxValue);

		if (strcmp(type, "P5") == 0) {  //칼라인지 흑백인지
			temp_depth = 1;   //흑백
		}
		else {
			temp_depth = 3;  //칼라
		}
	}
	else if (strcmp(strchr(fname, '.'), ".bmp") == 0 || strcmp(strchr(fname, '.'), ".BMP") == 0) {
		//bitmap file header 읽기
		BITMAPFILEHEADER bmfh;
		ar.Read((LPSTR)&bmfh, sizeof(bmfh));
		//bmp 화일임을 나타내는 "BM"마커가 있는지 확인
		if (bmfh.bfType != (WORD)(('M' << 8) | 'B')) return;

		//bitmap info header 읽기
		BITMAPINFOHEADER bih;
		ar.Read((LPSTR)&bih, sizeof(bih));
		temp_w = bih.biWidth;
		temp_h = bih.biHeight;
		temp_depth = bih.biBitCount / 8;

		//palette 처리
		if (depth == 1) {
			// palette 존재
			BYTE palette[256 * 4];
			ar.Read(palette, 256 * 4);
		}
		isbmp = true;
	}
	else if (strcmp(strchr(fname, '.'), ".raw") == 0 || strcmp(strchr(fname, '.'), ".RAW") == 0) {
		if (fp->GetLength() != 256 * 256) {
			AfxMessageBox("256 * 256 크기의 raw파일만 읽을 수 있습니다.");
			return;
		}
		temp_w = 256; temp_h = 256;
		temp_depth = 1;
	}
	if (ImageWidth != temp_w || ImageHeight != temp_h || depth != temp_depth) {
		AfxMessageBox("두 번째 파일의 height, width, depth가 다르면 읽을 수 없습니다.");
		return;
	}

	//메모리 할당 하는 부분

	InputImg2 = (unsigned char**)malloc(ImageHeight * sizeof(unsigned char*));
	
	for (int i = 0; i < ImageHeight; i++) {
		InputImg2[i] = (unsigned char*)malloc(ImageWidth * depth);
	}

	//영상 데이터 읽기

	if (!isbmp) {
		// 영상 데이터 읽기

		for (int i = 0; i < ImageHeight; i++) {
			ar.Read(InputImg2[i], ImageWidth * depth);
		}
	}
	else {
		// BMP영상 데이터 읽기
		BYTE nu[4 * 3];
		int widthfile;
		widthfile = (ImageWidth * 8 + 31) / 32 * 4;
		for (int i = 0; i < ImageHeight; i++) {

			if (depth == 1) {
				ar.Read(InputImg2[ImageHeight - 1 - i], ImageWidth * depth);
			}
			else {
				// BGR => RGB
				BYTE r, g, b;
				for (int j = 0; j < ImageWidth; j++) {
					ar.Read(&b, 1); ar.Read(&g, 1); ar.Read(&r, 1);
					InputImg2[ImageHeight - 1 - i][3 * j + 0] = r;
					InputImg2[ImageHeight - 1 - i][3 * j + 1] = g;
					InputImg2[ImageHeight - 1 - i][3 * j + 2] = b;
				}
			}

			if ((widthfile - ImageWidth) != 0) {
				ar.Read(nu, (widthfile - ImageWidth) * depth);
			}
		}
	}
}
