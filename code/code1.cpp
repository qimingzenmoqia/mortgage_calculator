#include <iostream>
#include <string>
#include <cmath>
#include <vector>

// Forward declaration of classes
class CalculationModule;
class DetailedViewModule;

// Enum for LoanType
enum class LoanType
{
    UNKNOWN,
    COMMERCIAL,
    HOUSING_PROVIDENT_FUND,
    COMBINED
};

// Enum for CalculationMethod
enum class CalculationMethod
{
    SIMPLE,
    COMPOUND
};

// Enum for InterestRateSelection
enum class InterestRateSelection
{
    FIXED,
    VARIABLE
};

// Class for LocalDate (assuming a simple representation for demonstration purposes)
class LocalDate
{
public:
    int day;
    int month;
    int year;

    LocalDate(int d, int m, int y) : day(d), month(m), year(y) {}
};

// Class for BigDecimal (simplified for demonstration)
class BigDecimal
{
public:
    double value;

    BigDecimal(double val) : value(val) {}
};

// Base class for Loan
class Loan
{
public:
    LoanType loanType;
    int loanTerm;
    CalculationMethod calculationMethod;
    BigDecimal loanAmount;
    InterestRateSelection interestRateSelection;
    BigDecimal loanInterest;
    LocalDate firstRepaymentDate;

    // Constructor
    Loan(LoanType type, int term, CalculationMethod method, BigDecimal amount,
         InterestRateSelection rateSelection, BigDecimal interest, LocalDate firstDate)
        : loanType(type),
          loanTerm(term),
          calculationMethod(method),
          loanAmount(amount),
          interestRateSelection(rateSelection),
          loanInterest(interest),
          firstRepaymentDate(firstDate) {}

    // Virtual destructor
    virtual ~Loan() = default;
};

// Derived class for CommercialLoan
class CommercialLoan : public Loan
{
public:
    // Constructor
    CommercialLoan();
    CommercialLoan(Loan loan) : Loan(loan) {}
};

// Derived class for HousingProvidentFundLoan
class HousingProvidentFundLoan : public Loan
{
public:
    // Constructor
    HousingProvidentFundLoan();
    HousingProvidentFundLoan(Loan loan) : Loan(loan) {}
};

// Derived class for CombinedLoan
class CombinedLoan : public Loan
{
public:
    int commercialLoanTerm;
    BigDecimal commercialLoanInterest;
    BigDecimal commercialLoanAmount;
    int housingProvidentFundLoanTerm;
    BigDecimal housingProvidentFundLoanInterest;
    BigDecimal housingProvidentFundLoanAmount;

    // Constructor
    CombinedLoan(int commTerm, BigDecimal commInterest, BigDecimal commAmount,
                 int hpflTerm, BigDecimal hpflInterest, BigDecimal hpflAmount,
                 LoanType type, int term, CalculationMethod method, BigDecimal amount,
                 InterestRateSelection rateSelection, BigDecimal interest, LocalDate firstDate)
        : Loan(type, term, method, amount, rateSelection, interest, firstDate),
          commercialLoanTerm(commTerm),
          commercialLoanInterest(commInterest),
          commercialLoanAmount(commAmount),
          housingProvidentFundLoanTerm(hpflTerm),
          housingProvidentFundLoanInterest(hpflInterest),
          housingProvidentFundLoanAmount(hpflAmount) {}
};

// Interface for CalculationModule
class CalculationModule
{
public:
    BigDecimal monthlyRepayment;
    BigDecimal totalRepayment;
    BigDecimal interestTotal;
    BigDecimal loanTotal;
    int loanTerm;

    // Virtual destructor
    virtual ~CalculationModule() = default;
};

// Class for DetailedViewModule
class DetailedViewModule
{
public:
    int period;
    BigDecimal repaidPrincipal;
    BigDecimal repaidInterest;
    BigDecimal monthlyRepayment;

    // Constructor
    DetailedViewModule(int p, BigDecimal principal, BigDecimal interest, BigDecimal repayment)
        : period(p),
          repaidPrincipal(principal),
          repaidInterest(interest),
          monthlyRepayment(repayment) {}
};

// Relationship between Loan and CalculationModule
class LoanCalculationRelation
{
public:
    Loan *loan;
    CalculationModule *calculationModule;

    // Constructor
    LoanCalculationRelation(Loan *l, CalculationModule *cm) : loan(l), calculationModule(cm) {}
};

// Relationship between CalculationModule and DetailedViewModule
class CalculationDetailedViewRelation
{
public:
    CalculationModule *calculationModule;
    DetailedViewModule *detailedViewModule;

    // Constructor
    CalculationDetailedViewRelation(CalculationModule *cm, DetailedViewModule *dvm)
        : calculationModule(cm), detailedViewModule(dvm) {}
};

void PrintInfo4Loan(Loan cl)
{
    std::cout << "期数为：" << cl.loanTerm << std::endl;
    std::cout << "计算类型：" << (cl.calculationMethod == CalculationMethod::SIMPLE ? "普通方式" : "混合方式") << std::endl;
    std::cout << "贷款总额：" << cl.loanAmount.value << std::endl;
    std::cout << "利息计算类型：" << (cl.interestRateSelection == InterestRateSelection::FIXED ? "定期" : "活期") << std::endl;
    std::cout << "贷款利率：" << cl.loanInterest.value << std::endl;
    std::cout << "还款时间：" << cl.firstRepaymentDate.year << "年 " << cl.firstRepaymentDate.month << "月 " << cl.firstRepaymentDate.day << "日" << std::endl;
}
void PrintInfo4CommercialLoan(CommercialLoan cl)
{
    std::cout << "商业贷款创建成功！" << std::endl;
    // std::cout << "期数为：" << cl.loanTerm << std::endl;
    // std::cout << "计算类型：" << (cl.calculationMethod == CalculationMethod::SIMPLE ? "普通方式" : "混合方式") << std::endl;
    // std::cout << "贷款总额：" << cl.loanAmount.value << std::endl;
    // std::cout << "利息计算类型：" << (cl.interestRateSelection == InterestRateSelection::FIXED ? "定期" : "活期") << std::endl;
    // std::cout << "贷款利率：" << cl.loanInterest.value << std::endl;
    // std::cout << "还款时间：" << cl.firstRepaymentDate.year << "年 " << cl.firstRepaymentDate.month << "月 " << cl.firstRepaymentDate.day << "日" << std::endl;
    PrintInfo4Loan(cl);
}

void PrintInfo4HPFLoan(HousingProvidentFundLoan cl)
{
    std::cout << "公积金贷款创建成功！" << std::endl;
    // std::cout << "期数为：" << cl.loanTerm << std::endl;
    // std::cout << "计算类型：" << (cl.calculationMethod == CalculationMethod::SIMPLE ? "普通方式" : "混合方式") << std::endl;
    // std::cout << "贷款总额：" << cl.loanAmount.value << std::endl;
    // std::cout << "利息计算类型：" << (cl.interestRateSelection == InterestRateSelection::FIXED ? "定期" : "活期") << std::endl;
    // std::cout << "贷款利率：" << cl.loanInterest.value << std::endl;
    // std::cout << "还款时间：" << cl.firstRepaymentDate.year << "年 " << cl.firstRepaymentDate.month << "月 " << cl.firstRepaymentDate.day << "日" << std::endl;
    PrintInfo4Loan(cl);
}

void PrintInfo4CombinedLoan(CombinedLoan cl)
{
    std::cout << "综合贷款创建成功！" << std::endl;
    PrintInfo4Loan(cl);
    std::cout << "-------以下是商业贷款部分信息--------" << std::endl;
    std::cout << "商业贷款期数:" << cl.commercialLoanTerm << std::endl;
    std::cout << "商业贷款利率:" << cl.commercialLoanInterest.value << std::endl;
    std::cout << "商业贷款总额:" << cl.commercialLoanAmount.value << std::endl;
    std::cout << "-------以下是公积金贷款部分信息--------" << std::endl;
    std::cout << "公积金贷款期数:" << cl.housingProvidentFundLoanTerm << std::endl;
    std::cout << "公积金贷款利率:" << cl.housingProvidentFundLoanInterest.value << std::endl;
    std::cout << "公积金贷款总额:" << cl.housingProvidentFundLoanAmount.value << std::endl;
}

int main()
{
    // Example usage of the classes
    LocalDate repaymentDate(1, 1, 2024);

    CommercialLoan commercialLoan(Loan(LoanType::COMBINED, 36, CalculationMethod::COMPOUND,
                                       150000, InterestRateSelection::FIXED, 0.03, repaymentDate));
    PrintInfo4CommercialLoan(commercialLoan);

    HousingProvidentFundLoan hpFundLoan(Loan(LoanType::COMBINED, 36, CalculationMethod::COMPOUND,
                                             150000, InterestRateSelection::FIXED, 0.03, repaymentDate));
    PrintInfo4HPFLoan(hpFundLoan);

    CombinedLoan combinedLoan(12, 0.05, 100000, 24, 0.04, 50000,
                              LoanType::COMBINED, 36, CalculationMethod::COMPOUND,
                              150000, InterestRateSelection::FIXED, 0.03, repaymentDate);

    PrintInfo4CombinedLoan(combinedLoan);

    return 0;
}
