#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Nov 18 15:00:24 2020

@author: trevorandrus
"""


#%% import packages and data

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn

FemtechData = pd.read_csv("data.csv")


# %% coercing strings to numeric, dropping average row

FemtechData = FemtechData.drop([71,])

FemtechData['Number of VPs and Above'] = pd.to_numeric(FemtechData['Number of VPs and Above'])
FemtechData['Number of Employees'] = pd.to_numeric(FemtechData['Number of Employees'])
FemtechData['Annual Revenue'] = pd.to_numeric(FemtechData['Annual Revenue'])
FemtechData['Amount of Funding'] = pd.to_numeric(FemtechData['Amount of Funding'])
FemtechData['Investors '] = pd.to_numeric(FemtechData['Investors '])
FemtechData['Revenue to Employees Ratio (revenue per 1 employee)'] = pd.to_numeric(FemtechData['Revenue to Employees Ratio (revenue per 1 employee)'])
FemtechData['Users/Patients'] = pd.to_numeric(FemtechData['Users/Patients'])

#################################################################################################################
#%% **********************************        SIZE         *********************************************
#################################################################################################################

#histogram of number of employees
plt.hist(FemtechData['Number of Employees'], bins = 5)

#histogram with outliers removed - (myriad genetics, goodstart genetics, the bump, progenity )
EmployeesNoOutliers = FemtechData[FemtechData['Number of Employees'] < 500]
plt.hist(EmployeesNoOutliers["Number of Employees"], bins = 7)
plt.title('Number of Employees')
plt.xlabel('Number of Employees')
plt.ylabel('Frequency (number of companies)')


#--------------------------------- Revenue Histogram ----------------------------
#histogram of revenue
plt.hist(FemtechData['Annual Revenue'], color='green')
plt.xlabel('Annual Revenue (billions of dollars)')
plt.ylabel('Frequency (number of companies)')

#histogram of revenue without myriad
RevenueNoOutliers = FemtechData['Annual Revenue'][FemtechData['Annual Revenue'] < 600000000]
plt.hist(RevenueNoOutliers, color='green')
plt.title('Revenue Per Employee')
plt.xlabel('Annual Revenue (millions of dollars)')
plt.ylabel('Frequency (number of companies)')

#histogram of revenue under 500k
RevenueUnder5 = FemtechData['Annual Revenue'][FemtechData['Annual Revenue'] < 5000000]
plt.hist(RevenueUnder5, bins = 8,  color='green')
plt.title('Annual Revenue Under 500K')
plt.xlabel('Annual Revenue (dollars)')
plt.ylabel('Frequency (number of companies)')

len(RevenueUnder5)

FemtechData['']


#--------------------------------- Revenue Per employee Histogram ----------------------------

#histogram of revenue per employee
plt.hist(FemtechData['Revenue to Employees Ratio (revenue per 1 employee)'], color='red')

#removing myriad, prelude, progyny, woom
RevenuePerEmployeeReduced = FemtechData['Revenue to Employees Ratio (revenue per 1 employee)'][FemtechData['Revenue to Employees Ratio (revenue per 1 employee)'] < 500000]
FemtechData.loc[[46, 55, 58, 70]]['Company Name']
plt.hist(RevenuePerEmployeeReduced, color = 'red')
plt.title('Revenue Per Employee')
plt.xlabel('Annual Revenue Per Employee (dollars)')
plt.ylabel('Frequency (number of companies)')


#--------------------------------- Employees v Amount of Funding ----------------------------

#number of employees v amount of funding
FemtechData.plot.scatter("Number of Employees", "Amount of Funding")
plt.title('# employees v amount of funding')

#number of employees v amount of funding, outliers removed
EmployeesNoOutliers.plot.scatter("Number of Employees", "Amount of Funding")
plt.title('# employees v amount of funding (outliers removed)')


#--------------------------------- Employees v Annual Revenue ----------------------------

#number of employees v annual revenue
FemtechData.plot.scatter("Number of Employees", "Annual Revenue")
plt.title('# employees v annual revenue')
plt.xlabel('Number of Employees')
plt.ylabel('Annual Revenue')

# without outliers
EmployeesNoOutliers.plot.scatter("Number of Employees", "Annual Revenue")
plt.title('# employees v annual revenue (no ourliers)')
plt.xlabel('Number of Employees')
plt.ylabel('Annual Revenue')

EmployeesUnder100 = FemtechData[FemtechData['Number of Employees'] < 100]

#just under 100 employees
EmployeesUnder100.plot.scatter("Number of Employees", "Annual Revenue")
plt.title('# employees v annual revenue (less than 100 employees)')
plt.xlabel('Number of Employees')
plt.ylabel('Annual Revenue')



# do vp's analysis here

FemtechDataWithoutMyriad.plot.scatter("Number of VPs and Above", "Annual Revenue")
plt.title('# vps v annual revenue')
plt.xlabel('Number of vps')
plt.ylabel('Annual Revenue')


FemtechData.plot.scatter("Number of VPs and Above", "Amount of Funding")
plt.title('# vps v annual revenue')
plt.xlabel('Number of vps')
plt.ylabel('Annual Revenue')


lowRev = FemtechData[FemtechData['Revenue to Employees Ratio (revenue per 1 employee)'] < 1500000]

lowRev.plot.scatter("Number of VPs and Above", "Revenue to Employees Ratio (revenue per 1 employee)")
plt.title('# vps v annual revenue')
plt.xlabel('Number of vps')
plt.ylabel('Annual Revenue')



EmployeesUnder100.plot.scatter("Number of VPs and Above", "Number of Employees")
plt.title('# vps v # employees')
plt.xlabel('Number of vps')
plt.ylabel('employees')



#################################################################################################################
#%% **********************************         AGE        *********************************************
#################################################################################################################


#--------------------------------- Age histogram ----------------------------
#histogram of company age
plt.hist(FemtechData['Years since Launch (As of 2020)'])
plt.title('Company Age')
plt.xlabel('Years Since Launch')
plt.ylabel('Frequency (number of companies)')

FemtechData['Years since Launch (As of 2020)'].mean()
FemtechData['Years since Launch (As of 2020)'].median()

#--------------------------------- Company age v annual revenue ----------------------------

#Myriad is always an outlier
FemtechData.plot.scatter("Years since Launch (As of 2020)", "Annual Revenue", color = 'green')
plt.title('Company Age v Annual Revenue')
plt.xlabel('Years Since Launch')
plt.ylabel('Annual Revenue (In millions)')

FemtechDataWithoutMyriad = FemtechData.drop([46,])

#company age v Annual Revenue (less myriad)
FemtechDataWithoutMyriad.plot.scatter("Years since Launch (As of 2020)", "Annual Revenue", color = 'green')
plt.title('Company Age v Annual Revenue')
plt.xlabel('Years Since Launch')
plt.ylabel('Annual Revenue (In millions)')


#--------------------------------- Company age v Amount of funding ----------------------------


#company age v Amount of funding (less myriad)
FemtechDataWithoutMyriad.plot.scatter("Years since Launch (As of 2020)", "Amount of Funding", color = 'green')
plt.title('Company Age v Amount of Funding')
plt.xlabel('Years Since Launch')
plt.ylabel('Amount of Funding')

FemtechData['Amount of Funding'].max()



#################################################################################################################
#%% **********************************        INVESTORS       *********************************************
#################################################################################################################


#--------------------------------- Investors v Revenue ----------------------------

#investors v revenue
FemtechData.plot.scatter("Investors ", "Annual Revenue")
plt.title('Investors v Annual Revenue')
plt.xlabel('Number of Investors')
plt.ylabel('Annual Revenue')

#without myriad
FemtechDataWithoutMyriad.plot.scatter("Investors ", "Annual Revenue")
plt.title('Investors v Annual Revenue (without myriad)')
plt.xlabel('Number of Investors')
plt.ylabel('Annual Revenue')


#--------------------------------- Investors v Amount of Funding ----------------------------

FemtechData.plot.scatter("Investors ", "Amount of Funding")
plt.title('Investors v Amount of Funding')
plt.xlabel('Number of Investors')
plt.ylabel('Amount of funding')


#--------------------------------- Investors v funding per investor ----------------------------

FemtechData['Funding Per Investor'] = FemtechData['Amount of Funding'] / FemtechData['Investors ']

FemtechData.plot.scatter("Investors ", "Funding Per Investor")
plt.title('Investors v Funding Per Investor')
plt.xlabel('Number of Investors')
plt.ylabel('Funding per Investor (Millions of Dollars)')







#################################################################################################################
#%% **********************************        CATEGORY       *********************************************
#################################################################################################################



#--------------------------------- Category v Avg Annual Revenue ----------------------------

FemtechData['Company Category'].value_counts()

###### should we also do the sum of revenue to see the distribution of revenue across market? #########

#making averages
meanFert = FemtechData['Annual Revenue'][FemtechData['Company Category'] == 'Fertility / Family Planning'].mean()
meanPreg = FemtechData['Annual Revenue'][FemtechData['Company Category'] == 'Pregnancy'].mean()
meanFam = FemtechData['Annual Revenue'][FemtechData['Company Category'] == 'Family Care/Post Natal Care'].mean()
meanMen = FemtechData['Annual Revenue'][FemtechData['Company Category'] == 'Menopause'].mean()
meanGen = FemtechData['Annual Revenue'][FemtechData['Company Category'] == "General Women's Health"].mean()

#creating average revenue data frame
AvgAnnualRevenue = pd.DataFrame({'Category':['Fertility/Family Planning', 'Family Care/Post Natal Care', 'Menopause', "General Women's Health", 'Pregnancy'], 'Annual Revenue':[meanFert, meanFam, meanMen, meanGen, meanPreg]})

#plot averages
AvgAnnualRevenue.plot.bar(x='Category', y='Annual Revenue')
plt.title('Annual Revenue by Category')
plt.xlabel('Company Category')
plt.ylabel('Average Annual Revenue')

#new averages without myriad
meanFert = FemtechDataWithoutMyriad['Annual Revenue'][FemtechDataWithoutMyriad['Company Category'] == 'Fertility / Family Planning'].mean()
meanPreg = FemtechDataWithoutMyriad['Annual Revenue'][FemtechDataWithoutMyriad['Company Category'] == 'Pregnancy'].mean()
meanFam = FemtechDataWithoutMyriad['Annual Revenue'][FemtechDataWithoutMyriad['Company Category'] == 'Family Care/Post Natal Care'].mean()
meanMen = FemtechDataWithoutMyriad['Annual Revenue'][FemtechDataWithoutMyriad['Company Category'] == 'Menopause'].mean()
meanGen = FemtechDataWithoutMyriad['Annual Revenue'][FemtechDataWithoutMyriad['Company Category'] == "General Women's Health"].mean()

#new dataframe
AvgAnnualRevenue = pd.DataFrame({'Category':['Fertility/Family Planning', 'Family Care/Post Natal Care', 'Menopause', "General Women's Health", 'Pregnancy'], 'Annual Revenue':[meanFert, meanFam, meanMen, meanGen, meanPreg]})

#new plot
AvgAnnualRevenue.plot.bar(x='Category', y='Annual Revenue')
plt.title('Annual Revenue by Category')
plt.xlabel('Company Category')
plt.ylabel('Average Annual Revenue')


#--------------------------------- Average Annual Revenue by Company (Fertility) ----------------------------

Fertility = FemtechData[FemtechData['Company Category'] == 'Fertility / Family Planning']
Fertility = Fertility.sort_values(by = 'Annual Revenue')
Fertility.plot.bar(x="Company Name", y='Annual Revenue')
plt.title('Annual Revenue by Company - Fertility')
plt.xlabel('Company')
plt.ylabel('Average Annual Revenue (hundred millions)')


#upper half
Fertility = FemtechData[FemtechData['Company Category'] == 'Fertility / Family Planning']
Fertility = Fertility.sort_values(by = 'Annual Revenue')
Fertility = Fertility[Fertility['Annual Revenue'] >= 3300000]
Fertility.plot.bar(x="Company Name", y='Annual Revenue')
plt.title('Annual Revenue by Company - Fertility')
plt.xlabel('Company')
plt.ylabel('Average Annual Revenue (hundred millions)')

#lower half
Fertility = FemtechData[FemtechData['Company Category'] == 'Fertility / Family Planning']
Fertility = Fertility.sort_values(by = 'Annual Revenue')
Fertility = Fertility[Fertility['Annual Revenue'] < 3300000]
Fertility.plot.bar(x="Company Name", y='Annual Revenue')
plt.title('Annual Revenue by Company - Fertility')
plt.xlabel('Company')
plt.ylabel('Average Annual Revenue (hundred millions)')


#--------------------------------- Average Annual Revenue by Company (Family) ----------------------------

Family = FemtechData[FemtechData['Company Category'] == 'Family Care/Post Natal Care']
Family = Family.sort_values(by = 'Annual Revenue')

Family.plot.bar(x="Company Name", y='Annual Revenue')
plt.title('Annual Revenue by Company - Family / Post Natal')
plt.xlabel('Company')
plt.ylabel('Average Annual Revenue (hundred millions)')


#--------------------------------- Average Annual Revenue by Company (Pregnancy) ----------------------------

Pregnancy = FemtechData[FemtechData['Company Category'] == 'Pregnancy']
Pregnancy = Pregnancy.sort_values(by = 'Annual Revenue')

Pregnancy.plot.bar(x="Company Name", y='Annual Revenue')
plt.title('Annual Revenue by Company - Pregnancy')
plt.xlabel('Company')
plt.ylabel('Average Annual Revenue')


#--------------------------------- Average Annual Revenue by Company (Women's Health) ----------------------------

WomHealth = FemtechData[FemtechData['Company Category'] == "General Women's Health"]
WomHealth = WomHealth.sort_values(by = 'Annual Revenue')

WomHealth.plot.bar(x="Company Name", y='Annual Revenue')
plt.title("Annual Revenue by Company - (Women's Health)")
plt.xlabel('Company')
plt.ylabel('Average Annual Revenue')

#dropping myriad
WomHealth = FemtechDataWithoutMyriad[FemtechDataWithoutMyriad['Company Category'] == "General Women's Health"]
WomHealth = WomHealth.sort_values(by = 'Annual Revenue')

WomHealth.plot.bar(x="Company Name", y='Annual Revenue')
plt.title("Annual Revenue by Company - (Women's Health)")
plt.xlabel('Company')
plt.ylabel('Average Annual Revenue')

#dropping goodstart genetics
WomHealth = WomHealth[WomHealth['Annual Revenue'] < 200000000]

WomHealth.plot.bar(x="Company Name", y='Annual Revenue')
plt.title("Annual Revenue by Company - (Women's Health)")
plt.xlabel('Company')
plt.ylabel('Average Annual Revenue')

#menopause only has 2 companies



#--------------------------------- Category v Avg Funding ----------------------------

# making averages
meanFertf = FemtechData['Amount of Funding'][FemtechData['Company Category'] == 'Fertility / Family Planning'].mean()
meanPregf = FemtechData['Amount of Funding'][FemtechData['Company Category'] == 'Pregnancy'].mean()
meanFamf = FemtechData['Amount of Funding'][FemtechData['Company Category'] == 'Family Care/Post Natal Care'].mean()
meanMenf = FemtechData['Amount of Funding'][FemtechData['Company Category'] == 'Menopause'].mean()
meanGenf = FemtechData['Amount of Funding'][FemtechData['Company Category'] == "General Women's Health"].mean()

AvgFunding = pd.DataFrame({'Category':['Fertility/Family Planning', 'Family Care/Post Natal Care', 'Menopause', "General Women's Health", 'Pregnancy'], 'Amount of Funding':[meanFertf, meanFamf, meanMenf, meanGenf, meanPregf]})

AvgFunding.plot.bar(x='Category', y='Amount of Funding')
plt.title('Funding by Category')
plt.xlabel('Company Category')
plt.ylabel('Amount of Funding')



#should we do breakdown of ammount of funding as well?


#################################################################################################################
#%% **********************************        MARKET SEGMENT      *********************************************
#################################################################################################################



#--------------------------------- Segment v Avg Annual Revenue ----------------------------
FemtechData['Market Segment (DTC, Employer etc...)'].value_counts()


meanDTC = FemtechData['Annual Revenue'][FemtechData['Market Segment (DTC, Employer etc...)'] == 'DTC'].mean()
meanProvider = FemtechData['Annual Revenue'][FemtechData['Market Segment (DTC, Employer etc...)'] == 'Provider'].mean()
meanEmployer = FemtechData['Annual Revenue'][FemtechData['Market Segment (DTC, Employer etc...)'] == 'Employer'].mean()
meanPayers = FemtechData['Annual Revenue'][FemtechData['Market Segment (DTC, Employer etc...)'] == 'Payers'].mean()
meanPharma = FemtechData['Annual Revenue'][FemtechData['Market Segment (DTC, Employer etc...)'] == 'Pharma'].mean()


AvgRevenueBySegment = pd.DataFrame({'Market Segment':['DTC', 'Provider', 'Employer', "Payers", 'Pharma'], 'Average Annual Revenue':[meanDTC, meanProvider, meanEmployer, meanPayers, meanPharma]})


AvgRevenueBySegment.plot.bar(x='Market Segment', y='Average Annual Revenue')
plt.title('Average Revenue by Segment')
plt.xlabel('Market Segment')
plt.ylabel('Average Annual Revenue')


#--------------------------------- Company v Annual Revenue (DTC) ----------------------------

DTC = FemtechData[FemtechData['Market Segment (DTC, Employer etc...)'] == 'DTC']
DTC = DTC.sort_values(by = 'Annual Revenue')
DTC.plot.bar(x='Company Name', y='Annual Revenue')
plt.title('Annual Revenue by Company - DTC')
plt.xlabel('Company')
plt.ylabel('Annual Revenue')


# without myriad
DTC = FemtechDataWithoutMyriad[FemtechDataWithoutMyriad['Market Segment (DTC, Employer etc...)'] == 'DTC']
DTC = DTC.sort_values(by = 'Annual Revenue')
DTC.plot.bar(x='Company Name', y='Annual Revenue')
plt.title('Annual Revenue by Company - DTC')
plt.xlabel('Company')
plt.ylabel('Annual Revenue')

# upper half
DTC = FemtechDataWithoutMyriad[FemtechDataWithoutMyriad['Market Segment (DTC, Employer etc...)'] == 'DTC']
DTC = DTC[DTC['Annual Revenue'] > 4000000]
DTC = DTC.sort_values(by = 'Annual Revenue')
DTC.plot.bar(x='Company Name', y='Annual Revenue')
plt.title('Annual Revenue by Company - DTC')
plt.xlabel('Company')
plt.ylabel('Annual Revenue')

#lower half
DTC = FemtechDataWithoutMyriad[FemtechDataWithoutMyriad['Market Segment (DTC, Employer etc...)'] == 'DTC']
DTC = DTC[DTC['Annual Revenue'] < 4000000]
DTC = DTC.sort_values(by = 'Annual Revenue')
DTC.plot.bar(x='Company Name', y='Annual Revenue')
plt.title('Annual Revenue by Company - DTC')
plt.xlabel('Company')
plt.ylabel('Annual Revenue')





#--------------------------------- Company v Annual Revenue (Provider) ----------------------------


Provider = FemtechData[FemtechData['Market Segment (DTC, Employer etc...)'] == 'Provider']
Provider = Provider.sort_values(by = 'Annual Revenue')
Provider.plot.bar(x='Company Name', y='Annual Revenue')
plt.title('Annual Revenue by Company - Provider')
plt.xlabel('Company')
plt.ylabel('Annual Revenue')


#--------------------------------- Company v Annual Revenue (Employer) ----------------------------


Employer = FemtechData[FemtechData['Market Segment (DTC, Employer etc...)'] == 'Employer']
Employer = Employer.sort_values(by = 'Annual Revenue')
Employer.plot.bar(x='Company Name', y='Annual Revenue')
plt.title('Annual Revenue by Company - Employer')
plt.xlabel('Company')
plt.ylabel('Annual Revenue')

#without progyny
Employer = FemtechData[FemtechData['Market Segment (DTC, Employer etc...)'] == 'Employer']
Employer = Employer.sort_values(by = 'Annual Revenue')
Employer = Employer[Employer['Annual Revenue'] < 200000000]
Employer.plot.bar(x='Company Name', y='Annual Revenue')
plt.title('Annual Revenue by Company - Employer')
plt.xlabel('Company')
plt.ylabel('Annual Revenue')


# payers and providers seem a little redundant - only 2 and 1 companies. 


#################################################################################################################
#%% **********************************        APP     *********************************************
#################################################################################################################

FemtechData['Is the Company App - Based?'].value_counts()


#--------------------------------- APP v Average Revenue ----------------------------
APP = FemtechData[FemtechData['Is the Company App - Based?'] == 'Yes']['Annual Revenue'].mean()
NOAPP = FemtechData[FemtechData['Is the Company App - Based?'] == 'No']['Annual Revenue'].mean()

AvgRevenueByAPP = pd.DataFrame({'APP Y/N':['Has App', 'No App'], 'Average Annual Revenue':[APP, NOAPP]})
AvgRevenueByAPP.plot.bar("APP Y/N", "Average Annual Revenue")
plt.title('Annual Revenue by App functionality')
plt.ylabel('Annual Revenue - (hundred millions)')

#without myriad
APP = FemtechDataWithoutMyriad[FemtechDataWithoutMyriad['Is the Company App - Based?'] == 'Yes']['Annual Revenue'].mean()
NOAPP = FemtechDataWithoutMyriad[FemtechDataWithoutMyriad['Is the Company App - Based?'] == 'No']['Annual Revenue'].mean()

AvgRevenueByAPP = pd.DataFrame({'APP Y/N':['Has App', 'No App'], 'Average Annual Revenue':[APP, NOAPP]})
AvgRevenueByAPP.plot.bar("APP Y/N", "Average Annual Revenue")
plt.title('Annual Revenue by App functionality')
plt.ylabel('Annual Revenue - (tens of millions)')



#--------------------------------- APP v Amount of Funding ----------------------------
APP = FemtechData[FemtechData['Is the Company App - Based?'] == 'Yes']['Amount of Funding'].mean()
NOAPP = FemtechData[FemtechData['Is the Company App - Based?'] == 'No']['Amount of Funding'].mean()


AvgRevenueByAPP = pd.DataFrame({'APP Y/N':['Has App', 'No App'], 'Amount of Funding':[APP, NOAPP]})
AvgRevenueByAPP.plot.bar("APP Y/N", "Amount of Funding")
plt.title('Amount of Funding by App functionality')
plt.ylabel('Amount of Funding - (tens of millions)')







#continue analysis of app ratings / number of ratings / downloads





#################################################################################################################
#%% **********************************      DIGITAL THERAPEUTIC     *********************************************
#################################################################################################################

FemtechData['Digital Therapeautic?'].value_counts()


#--------------------------------- Digital Therapeutic v Average Revenue ----------------------------


DT = FemtechData[FemtechData['Digital Therapeautic?'] == 'Yes']['Annual Revenue'].mean()
NOTDT = FemtechData[FemtechData['Digital Therapeautic?'] == 'No']['Annual Revenue'].mean()

AvgRevenueByAPP = pd.DataFrame({'Digital Therapeautic? Y/N':['Yes', 'No'], 'Average Annual Revenue':[DT, NOTDT]})
AvgRevenueByAPP.plot.bar("Digital Therapeautic? Y/N", "Average Annual Revenue")
plt.title('Annual Revenue by Digital Therapeutic')
plt.ylabel('Annual Revenue - (hundred millions)')

#without myriad
DT = FemtechDataWithoutMyriad[FemtechDataWithoutMyriad['Digital Therapeautic?'] == 'Yes']['Annual Revenue'].mean()
NOTDT = FemtechDataWithoutMyriad[FemtechDataWithoutMyriad['Digital Therapeautic?'] == 'No']['Annual Revenue'].mean()

AvgRevenueByDT = pd.DataFrame({'Digital Therapeautic?' :['Yes', 'No'], 'Average Annual Revenue':[DT, NOTDT]})
AvgRevenueByDT.plot.bar("Digital Therapeautic?", "Average Annual Revenue")
plt.title('Annual Revenue by Digital Therapeutic')
plt.ylabel('Annual Revenue - (tens of millions)')



#--------------------------------- Digital Therapeutic v Amount of Funding ----------------------------
DT = FemtechData[FemtechData['Digital Therapeautic?'] == 'Yes']['Amount of Funding'].mean()
NOTDT = FemtechData[FemtechData['Digital Therapeautic?'] == 'No']['Amount of Funding'].mean()


AvgRevenueByDT = pd.DataFrame({'APP Y/N':['Yes', 'No'], 'Amount of Funding':[DT, NOTDT]})
AvgRevenueByDT.plot.bar("APP Y/N", "Amount of Funding")
plt.title('Amount of Funding by Digital Therapeutic')
plt.ylabel('Amount of Funding - (tens of millions)')



FemtechData["Software Segment (Mental health, Women's software, etc...)"].value_counts()









