--Steve, Ruben, and Nick Project1

USE [master]
GO
/****** Object:  Database [CIS11101_Project01_Team01]    Script Date: 12/11/2019 9:40:16 AM ******/
CREATE DATABASE [CIS11101_Project01_Team01]
 CONTAINMENT = NONE
 ON  PRIMARY 
( NAME = N'CIS11101_Project01_Team01', FILENAME = N'C:\Program Files\Microsoft SQL Server\MSSQL13.MSSQLSERVER\MSSQL\DATA\CIS11101_Project01_Team01.mdf' , SIZE = 8192KB , MAXSIZE = UNLIMITED, FILEGROWTH = 10%)
 LOG ON 
( NAME = N'CIS11101_Project01_Team01_log', FILENAME = N'C:\Program Files\Microsoft SQL Server\MSSQL13.MSSQLSERVER\MSSQL\DATA\CIS11101_Project01_Team01_log.ldf' , SIZE = 1024KB , MAXSIZE = 2048GB , FILEGROWTH = 10%)
GO
ALTER DATABASE [CIS11101_Project01_Team01] SET COMPATIBILITY_LEVEL = 130
GO
IF (1 = FULLTEXTSERVICEPROPERTY('IsFullTextInstalled'))
begin
EXEC [CIS11101_Project01_Team01].[dbo].[sp_fulltext_database] @action = 'enable'
end
GO
ALTER DATABASE [CIS11101_Project01_Team01] SET ANSI_NULL_DEFAULT OFF 
GO
ALTER DATABASE [CIS11101_Project01_Team01] SET ANSI_NULLS OFF 
GO
ALTER DATABASE [CIS11101_Project01_Team01] SET ANSI_PADDING OFF 
GO
ALTER DATABASE [CIS11101_Project01_Team01] SET ANSI_WARNINGS OFF 
GO
ALTER DATABASE [CIS11101_Project01_Team01] SET ARITHABORT OFF 
GO
ALTER DATABASE [CIS11101_Project01_Team01] SET AUTO_CLOSE OFF 
GO
ALTER DATABASE [CIS11101_Project01_Team01] SET AUTO_SHRINK OFF 
GO
ALTER DATABASE [CIS11101_Project01_Team01] SET AUTO_UPDATE_STATISTICS ON 
GO
ALTER DATABASE [CIS11101_Project01_Team01] SET CURSOR_CLOSE_ON_COMMIT OFF 
GO
ALTER DATABASE [CIS11101_Project01_Team01] SET CURSOR_DEFAULT  GLOBAL 
GO
ALTER DATABASE [CIS11101_Project01_Team01] SET CONCAT_NULL_YIELDS_NULL OFF 
GO
ALTER DATABASE [CIS11101_Project01_Team01] SET NUMERIC_ROUNDABORT OFF 
GO
ALTER DATABASE [CIS11101_Project01_Team01] SET QUOTED_IDENTIFIER OFF 
GO
ALTER DATABASE [CIS11101_Project01_Team01] SET RECURSIVE_TRIGGERS OFF 
GO
ALTER DATABASE [CIS11101_Project01_Team01] SET  DISABLE_BROKER 
GO
ALTER DATABASE [CIS11101_Project01_Team01] SET AUTO_UPDATE_STATISTICS_ASYNC OFF 
GO
ALTER DATABASE [CIS11101_Project01_Team01] SET DATE_CORRELATION_OPTIMIZATION OFF 
GO
ALTER DATABASE [CIS11101_Project01_Team01] SET TRUSTWORTHY OFF 
GO
ALTER DATABASE [CIS11101_Project01_Team01] SET ALLOW_SNAPSHOT_ISOLATION OFF 
GO
ALTER DATABASE [CIS11101_Project01_Team01] SET PARAMETERIZATION SIMPLE 
GO
ALTER DATABASE [CIS11101_Project01_Team01] SET READ_COMMITTED_SNAPSHOT OFF 
GO
ALTER DATABASE [CIS11101_Project01_Team01] SET HONOR_BROKER_PRIORITY OFF 
GO
ALTER DATABASE [CIS11101_Project01_Team01] SET RECOVERY SIMPLE 
GO
ALTER DATABASE [CIS11101_Project01_Team01] SET  MULTI_USER 
GO
ALTER DATABASE [CIS11101_Project01_Team01] SET PAGE_VERIFY CHECKSUM  
GO
ALTER DATABASE [CIS11101_Project01_Team01] SET DB_CHAINING OFF 
GO
ALTER DATABASE [CIS11101_Project01_Team01] SET FILESTREAM( NON_TRANSACTED_ACCESS = OFF ) 
GO
ALTER DATABASE [CIS11101_Project01_Team01] SET TARGET_RECOVERY_TIME = 0 SECONDS 
GO
ALTER DATABASE [CIS11101_Project01_Team01] SET DELAYED_DURABILITY = DISABLED 
GO
EXEC sys.sp_db_vardecimal_storage_format N'CIS11101_Project01_Team01', N'ON'
GO
ALTER DATABASE [CIS11101_Project01_Team01] SET QUERY_STORE = OFF
GO
USE [CIS11101_Project01_Team01]
GO
ALTER DATABASE SCOPED CONFIGURATION SET LEGACY_CARDINALITY_ESTIMATION = OFF;
GO
ALTER DATABASE SCOPED CONFIGURATION SET MAXDOP = 0;
GO
ALTER DATABASE SCOPED CONFIGURATION SET PARAMETER_SNIFFING = ON;
GO
ALTER DATABASE SCOPED CONFIGURATION SET QUERY_OPTIMIZER_HOTFIXES = OFF;
GO
USE [CIS11101_Project01_Team01]
GO
/****** Object:  Table [dbo].[CoreCourses]    Script Date: 12/11/2019 9:40:16 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[CoreCourses](
	[StudentID] [int] NOT NULL,
	[CourseName] [varchar](50) NULL,
	[CourseLineNumber] [int] NOT NULL,
 CONSTRAINT [PK_CoreCourses] PRIMARY KEY CLUSTERED 
(
	[CourseLineNumber] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Education]    Script Date: 12/11/2019 9:40:16 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Education](
	[City] [varchar](50) NULL,
	[State] [varchar](50) NULL,
	[DateFrom] [datetime] NULL,
	[DateTo] [datetime] NULL,
	[ProgramOfStudy] [varchar](50) NULL,
	[GPA] [float] NULL,
	[Degree] [varchar](50) NULL,
	[EducationLineNumber] [int] NOT NULL,
	[StudentID] [int] NOT NULL,
 CONSTRAINT [PK_Education1] PRIMARY KEY CLUSTERED 
(
	[EducationLineNumber] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Employer]    Script Date: 12/11/2019 9:40:16 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Employer](
	[EmployerName] [varchar](50) NOT NULL,
	[Address] [varchar](30) NOT NULL,
	[City] [varchar](20) NOT NULL,
	[State] [varchar](20) NOT NULL,
	[Zip] [varchar](20) NOT NULL,
	[EmployerID] [int] NOT NULL,
	[Phone] [varchar](20) NOT NULL,
	[Fax] [varchar](20) NULL,
	[ContactName] [varchar](50) NOT NULL,
	[ContactTitle] [varchar](50) NOT NULL,
	[Comments] [varchar](max) NULL,
 CONSTRAINT [PK_Employer] PRIMARY KEY CLUSTERED 
(
	[EmployerID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]
GO
/****** Object:  Table [dbo].[EmployerJobAnnounnce]    Script Date: 12/11/2019 9:40:16 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[EmployerJobAnnounnce](
	[TypeOfBusiness] [varchar](50) NULL,
	[TitleOfJob] [varchar](50) NULL,
	[Location] [varchar](50) NULL,
	[Qualifications] [varchar](max) NULL,
	[Description] [varchar](50) NULL,
	[WorkSchedule] [varchar](50) NULL,
	[HoursPerWeek] [int] NULL,
	[Salary] [varchar](50) NULL,
	[RatePerHour] [decimal](3, 2) NULL,
	[Benefits] [varchar](max) NULL,
	[PostingNumber] [int] NOT NULL,
	[EmployerID] [int] NULL,
	[NumberOfOpenings] [int] NULL,
	[CopiersTo] [varchar](50) NULL,
 CONSTRAINT [PK_EmpJobAnnounnce] PRIMARY KEY CLUSTERED 
(
	[PostingNumber] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Student]    Script Date: 12/11/2019 9:40:16 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Student](
	[StudentID] [int] NOT NULL,
	[Name] [varchar](60) NOT NULL,
	[DateApplied] [datetime] NOT NULL,
	[StreetAddress] [varchar](50) NOT NULL,
	[City] [varchar](50) NOT NULL,
	[State] [varchar](30) NOT NULL,
	[Zip] [varchar](20) NOT NULL,
	[Phone] [varchar](20) NOT NULL,
	[Email] [varbinary](50) NOT NULL,
	[CitizenStatus] [varchar](30) NOT NULL,
	[SchoolStatus] [varchar](30) NOT NULL,
	[Program] [varchar](50) NOT NULL,
	[HFCCredit] [int] NOT NULL,
	[TransferCredit] [int] NOT NULL,
	[GPA] [decimal](3, 2) NOT NULL,
	[CoreGPA] [decimal](3, 2) NOT NULL,
	[GraduationDate] [datetime] NOT NULL,
	[AdditionalTrain] [varchar](max) NULL,
	[AdditionalSkills] [varchar](max) NULL,
	[WorkNarrative] [varchar](max) NULL,
	[WorkCampus] [varchar](20) NOT NULL,
	[WorkSchedule] [varchar](20) NOT NULL,
	[CoopCredit] [bit] NOT NULL,
	[Activities] [varchar](max) NULL,
	[CareerGoals] [varchar](max) NULL,
	[HealthStatus] [varchar](max) NOT NULL,
 CONSTRAINT [PK_Student] PRIMARY KEY CLUSTERED 
(
	[StudentID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]
GO
/****** Object:  Table [dbo].[StudentApplication]    Script Date: 12/11/2019 9:40:16 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[StudentApplication](
	[IsEligible] [bit] NOT NULL,
	[StudentAgree] [bit] NOT NULL,
	[RecGuide] [bit] NOT NULL,
	[StudentResume] [bit] NOT NULL,
	[PostNumber] [int] NOT NULL,
	[ApplicationID] [int] NOT NULL,
	[StudentID] [int] NOT NULL,
 CONSTRAINT [PK_StudentApp] PRIMARY KEY CLUSTERED 
(
	[ApplicationID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[StudentsToBeInterviewed]    Script Date: 12/11/2019 9:40:16 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[StudentsToBeInterviewed](
	[PostTerms] [bit] NULL,
	[EmployerID] [int] NOT NULL,
	[PostNumber] [int] NOT NULL,
	[StudentID] [int] NOT NULL,
	[ToBeInterviewedLineNumber] [int] IDENTITY(1,1) NOT NULL,
 CONSTRAINT [PK_StudentsToBeInterviewed] PRIMARY KEY CLUSTERED 
(
	[ToBeInterviewedLineNumber] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[WorkExperience]    Script Date: 12/11/2019 9:40:16 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[WorkExperience](
	[CompanyName] [varchar](50) NULL,
	[City] [varchar](50) NULL,
	[State] [varchar](50) NULL,
	[DateFrom] [datetime] NULL,
	[DateTo] [datetime] NULL,
	[JobTitle] [varchar](50) NULL,
	[StudentID] [int] NOT NULL,
	[WorkExperienceLineNumber] [int] IDENTITY(1,1) NOT NULL,
 CONSTRAINT [PK_WorkExperience] PRIMARY KEY CLUSTERED 
(
	[WorkExperienceLineNumber] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
ALTER TABLE [dbo].[CoreCourses]  WITH CHECK ADD  CONSTRAINT [FK_CoreCourses_Student] FOREIGN KEY([StudentID])
REFERENCES [dbo].[Student] ([StudentID])
GO
ALTER TABLE [dbo].[CoreCourses] CHECK CONSTRAINT [FK_CoreCourses_Student]
GO
ALTER TABLE [dbo].[Education]  WITH CHECK ADD  CONSTRAINT [FK_StudentId] FOREIGN KEY([StudentID])
REFERENCES [dbo].[Student] ([StudentID])
GO
ALTER TABLE [dbo].[Education] CHECK CONSTRAINT [FK_StudentId]
GO
ALTER TABLE [dbo].[EmployerJobAnnounnce]  WITH CHECK ADD  CONSTRAINT [FK_EmployerID] FOREIGN KEY([EmployerID])
REFERENCES [dbo].[Employer] ([EmployerID])
GO
ALTER TABLE [dbo].[EmployerJobAnnounnce] CHECK CONSTRAINT [FK_EmployerID]
GO
ALTER TABLE [dbo].[StudentApplication]  WITH CHECK ADD  CONSTRAINT [FK_StudentApplication_EmpJobAnnounnce] FOREIGN KEY([PostNumber])
REFERENCES [dbo].[EmployerJobAnnounnce] ([PostingNumber])
GO
ALTER TABLE [dbo].[StudentApplication] CHECK CONSTRAINT [FK_StudentApplication_EmpJobAnnounnce]
GO
ALTER TABLE [dbo].[StudentApplication]  WITH CHECK ADD  CONSTRAINT [FK_StudentApplication_Student] FOREIGN KEY([StudentID])
REFERENCES [dbo].[Student] ([StudentID])
GO
ALTER TABLE [dbo].[StudentApplication] CHECK CONSTRAINT [FK_StudentApplication_Student]
GO
ALTER TABLE [dbo].[StudentsToBeInterviewed]  WITH CHECK ADD  CONSTRAINT [FK_StudentsToBeInterviewed_EmpJobAnnounnce] FOREIGN KEY([PostNumber])
REFERENCES [dbo].[EmployerJobAnnounnce] ([PostingNumber])
GO
ALTER TABLE [dbo].[StudentsToBeInterviewed] CHECK CONSTRAINT [FK_StudentsToBeInterviewed_EmpJobAnnounnce]
GO
ALTER TABLE [dbo].[StudentsToBeInterviewed]  WITH CHECK ADD  CONSTRAINT [FK_StudentsToBeInterviewed_Employer] FOREIGN KEY([EmployerID])
REFERENCES [dbo].[Employer] ([EmployerID])
GO
ALTER TABLE [dbo].[StudentsToBeInterviewed] CHECK CONSTRAINT [FK_StudentsToBeInterviewed_Employer]
GO
ALTER TABLE [dbo].[StudentsToBeInterviewed]  WITH CHECK ADD  CONSTRAINT [FK_StudentsToBeInterviewed_Student] FOREIGN KEY([StudentID])
REFERENCES [dbo].[Student] ([StudentID])
GO
ALTER TABLE [dbo].[StudentsToBeInterviewed] CHECK CONSTRAINT [FK_StudentsToBeInterviewed_Student]
GO
ALTER TABLE [dbo].[WorkExperience]  WITH CHECK ADD  CONSTRAINT [FK_WorkExperience_Student] FOREIGN KEY([StudentID])
REFERENCES [dbo].[Student] ([StudentID])
GO
ALTER TABLE [dbo].[WorkExperience] CHECK CONSTRAINT [FK_WorkExperience_Student]
GO
USE [master]
GO
ALTER DATABASE [CIS11101_Project01_Team01] SET  READ_WRITE 
GO
