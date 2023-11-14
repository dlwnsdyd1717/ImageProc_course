
// imageproc_20210791Doc.h: Cimageproc20210791Doc 클래스의 인터페이스
//


#pragma once


class Cimageproc20210791Doc : public CDocument
{
protected: // serialization에서만 만들어집니다.
	Cimageproc20210791Doc() noexcept;
	DECLARE_DYNCREATE(Cimageproc20210791Doc)

// 특성입니다.
public:

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 구현입니다.
public:
	virtual ~Cimageproc20210791Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 검색 처리기에 대한 검색 콘텐츠를 설정하는 도우미 함수
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
//	unsigned char InputImg[256][256];  //[y]축 [x]축
//	unsigned char InputImg2[256][256];  //[y]축 [x]축
//	unsigned char ResultImg[256][256];  //[y]축 [x]축

	//입력 이미지
	unsigned char **InputImg;      //[x][y]
	unsigned char **InputImg2;     //[x][y]
	//출력 이미지
	unsigned char **ResultImg;     //[x][y]

	int ImageWidth;   // 영상의 넓이
	int ImageHeight;  // 영상의 높이
	int depth;     // 1 == 흑백 , 3 == 칼라

	int gImageWidth;   //달라진 영상의 넓이
	int gImageHeight;  //달라진 영상의 높이
	unsigned char** gResultImg;     //[x][y]  //달라지는 이미지 출력

	void LoadImageFile(CArchive& ar);
	void LOadSecondImageFile(CArchive& ar);
};
