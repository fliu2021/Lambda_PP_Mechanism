void test_bin_width() {
    // 创建相同数据，不同bin宽度的直方图
    const int n = 1000;
    Double_t data[n];
    TRandom3 rnd(42);
    
    // 生成测试数据：正态分布，均值=5，标准差=2
    for (int i = 0; i < n; i++) {
        data[i] = rnd.Gaus(5.0, 2.0);
    }
    
    // 创建不同bin宽度的直方图
    TH1D* hist_fine = new TH1D("fine", "Fine Binning", 100, -10, 20);   // bin宽度=0.1
    TH1D* hist_coarse = new TH1D("coarse", "Coarse Binning", 10, -10, 20); // bin宽度=1.0
    TH1D* hist_very_coarse = new TH1D("vcoarse", "Very Coarse Binning", 1, -10, 20); // bin宽度=2.0
    
    // 填充相同的数据
    for (int i = 0; i < n; i++) {
        hist_fine->Fill(data[i]);
        hist_coarse->Fill(data[i]);
        hist_very_coarse->Fill(data[i]);
    }
    
    // 比较统计结果
    cout << "=== 统计量比较 ===" << endl;
    cout << "精细分bin (100 bins):" << endl;
    cout << "  平均值: " << hist_fine->GetMean() << " ± " << hist_fine->GetMeanError() << endl;
    cout << "  标准差: " << hist_fine->GetRMS() << " ± " << hist_fine->GetRMSError() << endl;
    cout << "  条目数: " << hist_fine->GetEntries() << endl;
    
    cout << "\n中等分bin (10 bins):" << endl;
    cout << "  平均值: " << hist_coarse->GetMean() << " ± " << hist_coarse->GetMeanError() << endl;
    cout << "  标准差: " << hist_coarse->GetRMS() << " ± " << hist_coarse->GetRMSError() << endl;
    cout << "  条目数: " << hist_coarse->GetEntries() << endl;
    
    cout << "\n粗糙分bin (5 bins):" << endl;
    cout << "  平均值: " << hist_very_coarse->GetMean() << " ± " << hist_very_coarse->GetMeanError() << endl;
    cout << "  标准差: " << hist_very_coarse->GetRMS() << " ± " << hist_very_coarse->GetRMSError() << endl;
    cout << "  条目数: " << hist_very_coarse->GetEntries() << endl;
    
    // 用TMath直接计算作为基准
    cout << "\n=== TMath直接计算 (基准) ===" << endl;
    cout << "  平均值: " << TMath::Mean(n, data) << endl;
    cout << "  标准差: " << TMath::RMS(n, data) << endl;
}
