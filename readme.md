
# colormap
輝度情報からカラーマップを作成し、QImageにしてGUIに表示するプログラムです。  
GUIにはQtを使用しています。  

## Demo
![colormap](https://user-images.githubusercontent.com/12496951/180650452-07f8ec16-05cb-47ed-9a32-e8fc47cbad18.PNG)

## 計算式
私の備忘録も兼ねて、計算式の過程も記載しています。  
ここでは、基本的な式を変形して利用しています。  

以下のような式です。  
Y(輝度) = 0.299R + 0.587G + 0.114B  
Cr(赤さ) = R - Y  
Cb(青さ) = B - Y  

式中の「RGB」は、Red, Green, Blueのことです。  
この式はY, R-Y, B-Y信号を求めている式です。  
YCbCrを求める式とはちょいと違いますのでご注意ください。  
赤さと青さは以下のように変形するとRGBの数値から求めることが出来ます。  

Cr = R - (0.299R + 0.587G + 0.114B)  
   = R - 0.299R - 0.587G - 0.114B  
   = 0.701R - 0.587G - 0.114B  

Cb = B - (0.299R + 0.587G + 0.114B)  
   = B - 0.299R - 0.587G - 0.114B  
   = -0.299R - 0.587G + 0.886B  

本プログラムのカラーマップも、上述式を良い感じに変形してRGBを求めています。  

Cr = R - Y  
-R = -Y - Cr  
R = Y + Cr  

Cb = B - Y  
-B = -Y - Cb  
B = Y + Cb  

Y = 0.299R + 0.587G + 0.114B  
Y = 0.299(Y + Cr) + 0.587G + 0.114(Y + Cb)  
Y = 0.299Y + 0.299Cr + 0.587G + 0.114Y + 0.114Cb  
Y - 0.299Y - 0.114Y = 0.299Cr + 0.587G + 0.114Cb  
0.587Y = 0.299Cr + 0.587G + 0.114Cb  
-0.587G = -0.587Y + 0.299Cr + 0.114Cb  
G = Y - (0.299/0.587)Cr - (0.114/0.587)Cb  

## Dependency
- MSVC 15+  
- Qt 5.13.1

## Build
CMakeLists.txtではQTDIRを環境変数から取得して使用しています。  
また、ここではWSL2とPowerShell、CMakeを使用したビルド方法を記述します。  
CMakeは環境変数のPATHへ追加しています。  

1. このリポジトリをクローンします。  
2. 以下のコマンドでビルドします。  
   ex. VS2017 の場合  
   powershell.exe cmake -S . -B build -G "\"Visual Studio 15 2017 Win64\""  
   powershell.exe cmake --build build  

   ex. VS2019以上の場合  
   powershell.exe cmake -S . -B build  
   powershell.exe cmake --build build  

3. 実行時に必要なDLL群はコピーしていません。実行の際には注意してください。


## License
This software is released under the MIT License, see LICENSE.

## References
[C言語で学ぶ実践CG・映像合成](https://www.ohmsha.co.jp/book/9784274500169/)  
[コンピュータ画像処理(改訂2版)](https://www.ohmsha.co.jp/book/9784274228193/)  

