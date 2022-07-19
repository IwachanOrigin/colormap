
# colormap
輝度情報からカラーマップを作成し、QImageにしてGUIに表示するプログラムです。  
GUIにはQtを使用しています。  

## Demo


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
