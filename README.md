# hw01_README

## Description
本項目主要用於矩陣運算W * X + B = Z並且依用戶需求對Z矩陣進行激活函數( 如 ReLU 和 sigmoid )應用、另提供不同維度矩陣運算。

## 功能
- 初始化矩阵。
- 执行稀疏矩阵加法。
- 执行稀疏矩阵乘法。
- 应用激活函数（ReLU 和 sigmoid）到矩阵。

## Requirement
程式碼以C語言進行編成，請確保您的裝置上有可執行C語言的環境。

## Install
1. 複製github倉庫網址：
   ```bash
   git clone https://github.com/liao-046/my_data_structure.git
2. 進入項目文件夾：
   ```bash
   cd my_data_structure
3. 查看內部檔案：
   ls  #應有hw01.c、myfunc.c、myfunc.h、makefile、hw01 
5. 下make編譯為hw01：
   ```bash
   make
6. 執行檔案：
   ```bash
   ./hw01
