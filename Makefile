export CGO_ENABLED=1
export WDIR=${PWD}

all: windows

windows:
	CGO_LDFLAGS_ALLOW=".*" CGO_CFLAGS="-I${WDIR}/include" CGO_LDFLAGS="-L${WDIR}/lib/Windows -Wl,--enable-stdcall-fixup,-rpath=${WDIR}/lib/Windows -lHCNetSDK" GOOS=windows CC=x86_64-w64-mingw32-gcc CXX=x86_64-w64-mingw32-g++ go build -ldflags "-s -w" -o build/Windows/hk.exe src/HCNetSDK.go
	cp lib/Windows/HCNetSDK.dll build/Windows/
	cp lib/Windows/HCCore.dll build/Windows/
	cp -r lib/Windows/HCNetSDKCom/ build/Windows/

clean:
	rm -r build/
