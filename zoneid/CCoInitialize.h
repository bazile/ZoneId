//
// via Do you know when your destructors run? Part 1.
// http://blogs.msdn.com/b/oldnewthing/archive/2004/05/20/135841.aspx
//

class CCoInitialize
{
public:
	CCoInitialize() : m_hr(CoInitialize(NULL)) { }
	~CCoInitialize() { if (SUCCEEDED(m_hr)) CoUninitialize(); }
	operator HRESULT() const { return m_hr; }
	HRESULT m_hr;
};
