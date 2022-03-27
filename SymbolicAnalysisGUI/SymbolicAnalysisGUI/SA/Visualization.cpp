#include "Visualization.h"
#include <iostream>


SymbolicAnalysis* ptr;

void GLshowSCs();
void analyzeKey(unsigned char key);
void drawCoordinatePlane();

void showLocalization();
void keyboardLocalization(unsigned char key, int x, int y);

void showBalancingMethod();
void keyboardBalancingMethod(unsigned char key, int x, int y);

void showJohnsonAlgorithm();
void keyboardJohnsonAlgorithm(unsigned char key, int x, int y);

void showRomanovskyAlgorithm();
void keyboardRomanovskyAlgorithm(unsigned char key, int x, int y);


Visualization::Visualization(const float& left, const float& right, const float& top, const float& bot,
    const string& formulaX, const string& formulaY,
    const int& maxIter, const int& dotsPerCell, const int& splitNum,
    const float& eps,
    const string& projectiveFormulaX, const string& projectiveFormulaY,
    const int& maxIterProjective, const int& splitNumProjective,
    const string& arcWeightFormula)
    : symbolicAnalysis(left, right, top, bot, formulaX, formulaY, maxIter, dotsPerCell, splitNum,
        eps, projectiveFormulaX, projectiveFormulaY, maxIterProjective, splitNumProjective, arcWeightFormula),
    winSizeY(1000), winSizeX(1000 * (right - left) / (top - bot))
{
    ptr = &symbolicAnalysis;
};

void Visualization::Localization()
{
    ptr->prepareLocalization();

    info = ptr->getInfo();

    cout << "Vertexes\t" << info["v"][0] << endl;

    cout << "SCs\t\t" << info["sc"][0] << " -> ";
    for (auto& sc : info["scALL"])
    {
        cout << sc << ", ";
    }
    cout << endl;

    cout << "Diameter\t" << info["d"][0] << endl;

    cout << "Time\t\t" << info["t"][0] << endl;

    invokeWindow(showLocalization, keyboardLocalization);
}

void Visualization::BalancingMethod()
{
    ptr->prepareBalancingMethod();

    info = ptr->getInfo();

    cout << "Vertexes\t" << info["v"][0] << endl;

    cout << "SCs\t\t" << info["sc"][0] << " -> ";
    for (auto& sc : info["scALL"])
    {
        cout << sc << ", ";
    }
    cout << endl;

    cout << "Diameter\t" << info["d"][0] << endl;

    cout << "Time\t\t" << info["t"][0] << endl;

    invokeWindow(showBalancingMethod, keyboardBalancingMethod);
}

void Visualization::JohnsonAlgorithm()
{
    ptr->prepareJohnson();

    info = ptr->getInfo();

    cout << "Vertexes\t" << info["v"][0] << endl;

    cout << "SCs\t\t" << info["sc"][0] << " -> ";
    for (auto& sc : info["scALL"])
    {
        cout << sc << ", ";
    }
    cout << endl;

    cout << "Diameter\t" << info["d"][0] << endl;

    cout << "Time\t\t" << info["t"][0] << endl;

    cout << "Max cycle\t" << info["mc"][0] << endl;

    invokeWindow(showJohnsonAlgorithm, keyboardJohnsonAlgorithm);
}

void Visualization::ProjectiveLocalization()
{
    ptr->prepareProjectiveLocalization();

    info = ptr->getInfo();

    cout << "Vertexes\t" << info["v"][0] << endl;

    cout << "SCs\t\t" << info["sc"][0] << " -> ";
    for (auto& sc : info["scALL"])
    {
        cout << sc << ", ";
    }
    cout << endl;

    cout << "Diameter\t" << info["d"][0] << endl;

    cout << "Time\t\t" << info["t"][0] << endl;

    cout << "Proj vert\t" << info["vp"][0] << endl;

    cout << "Proj SCs\t" << info["scp"][0] << " -> ";
    for (auto& sc : info["scALLp"])
    {
        cout << sc << ", ";
    }
    cout << endl;

    cout << "Proj Diameter\t" << info["dp"][0] << endl;
}

void Visualization::RomanovskyAlgorithm()
{
    ptr->prepareRomanovskyAlgorithm();

    info = ptr->getInfo();

    cout << "Vertexes\t" << info["v"][0] << endl;

    cout << "SCs\t\t" << info["sc"][0] << " -> ";
    for (auto& sc : info["scALL"])
    {
        cout << sc << ", ";
    }
    cout << endl;

    cout << "Diameter\t" << info["d"][0] << endl;

    cout << "Time\t\t" << info["t"][0] << endl;

    for (int i = 0; i < info["scOrder"].size(); i++)
    {
        if (info["min"][i][0] == '-' && info["max"][i][0] != '-')
        {
            cout << info["scOrder"][i] << "\t" << info["min"][i] << "\t" << info["max"][i] << "\tzero in" << endl;
        }
        else
        {
            cout << info["scOrder"][i] << "\t" << info["min"][i] << "\t" << info["max"][i] << endl;
        }
    }

    invokeWindow(showRomanovskyAlgorithm, keyboardRomanovskyAlgorithm);
}

void Visualization::MorseSpectrum()
{
    ptr->prepareMorseSpectrum();

    info = ptr->getInfo();

    cout << "Vertexes\t" << info["v"][0] << endl;

    cout << "SCs\t\t" << info["sc"][0] << " -> ";
    for (auto& sc : info["scALL"])
    {
        cout << sc << ", ";
    }
    cout << endl;

    cout << "Diameter\t" << info["d"][0] << endl;

    cout << "Time\t\t" << info["t"][0] << endl;

    cout << "Proj vert\t" << info["vp"][0] << endl;

    cout << "Proj SCs\t" << info["scp"][0] << " -> ";
    for (auto& sc : info["scALLp"])
    {
        cout << sc << ", ";
    }
    cout << endl;

    cout << "Proj Diameter\t" << info["dp"][0] << endl;

    for (int i = 0; i < info["scOrder"].size(); i++)
    {
        if (info["min"][i][0] == '-' && info["max"][i][0] != '-')
        {
            cout << info["scOrder"][i] << "\t" << info["min"][i] << "\t" << info["max"][i] << "\tzero in" << endl;
        }
        else
        {
            cout << info["scOrder"][i] << "\t" << info["min"][i] << "\t" << info["max"][i] << endl;
        }
    }
}

void Visualization::maxCycleInProjective()
{
    ptr->prepareMaxCycleInProjective();

    info = ptr->getInfo();

    cout << "Vertexes\t" << info["v"][0] << endl;

    cout << "SCs\t\t" << info["sc"][0] << " -> ";
    for (auto& sc : info["scALL"])
    {
        cout << sc << ", ";
    }
    cout << endl;

    cout << "Diameter\t" << info["d"][0] << endl;

    cout << "Time\t\t" << info["t"][0] << endl;

    cout << "Max cycle\t" << info["mc"][0] << endl;

    cout << "MC Proj vert\t" << info["vp"][0] << endl;

    cout << "MC Proj SCs\t" << info["scp"][0] << " -> ";
    for (auto& sc : info["scALLp"])
    {
        cout << sc << ", ";
    }
    cout << endl;

    cout << "MC Proj Diam\t" << info["dp"][0] << endl;
}

void Visualization::maxCycleMorseSpectrum()
{
    ptr->prepareMaxCycleMorseSpectrum();

    info = ptr->getInfo();

    cout << "Vertexes\t" << info["v"][0] << endl;

    cout << "SCs\t\t" << info["sc"][0] << " -> ";
    for (auto& sc : info["scALL"])
    {
        cout << sc << ", ";
    }
    cout << endl;

    cout << "Diameter\t" << info["d"][0] << endl;

    cout << "Time\t\t" << info["t"][0] << endl;

    cout << "Max cycle\t" << info["mc"][0] << endl;

    cout << "MC Proj vert\t" << info["vp"][0] << endl;

    cout << "MC Proj SCs\t" << info["scp"][0] << " -> ";
    for (auto& sc : info["scALLp"])
    {
        cout << sc << ", ";
    }
    cout << endl;

    cout << "MC Proj Diam\t" << info["dp"][0] << endl;

    for (int i = 0; i < info["scOrder"].size(); i++)
    {
        if (info["min"][i][0] == '-' && info["max"][i][0] != '-')
        {
            cout << info["scOrder"][i] << "\t" << info["min"][i] << "\t" << info["max"][i] << "\tzero in" << endl;
        }
        else
        {
            cout << info["scOrder"][i] << "\t" << info["min"][i] << "\t" << info["max"][i] << endl;
        }
    }
}

unordered_map<string, vector<string>>& Visualization::getInfo()
{
    return info;
}

void Visualization::invokeWindow(void (*display)(), void (*keyboard)(unsigned char, int, int))
{
    char fakeParam[] = "fake";
    char* fakeargv[] = { fakeParam, NULL };
    int fakeargc = 1;
    glutInit(&fakeargc, fakeargv);
    //glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION);
    glutInitWindowSize(winSizeX, winSizeY);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Visualization");

    glClearColor(1, 1, 1, 1);

    gluPerspective(45.0, winSizeX / winSizeY, 0.1, 400.0);
    glTranslatef(0.0, 0.0, -10.0);

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
}

void GLshowSCs()
{
    int counter = 0;
    for (const auto& strongComponent : ptr->getSCs())
    {
        glColor3f(ptr->getColors()[counter][0], ptr->getColors()[counter][1], ptr->getColors()[counter][2]);
        ++counter;

        for (auto& cell : strongComponent)
        {
            float x, y;
            ptr->getLeftTopXY(x, y, cell);

            glVertex2f(x, y);
            glVertex2f(x + ptr->getCellSizeX(), y);
            glVertex2f(x + ptr->getCellSizeX(), y - ptr->getCellSizeY());
            glVertex2f(x, y - ptr->getCellSizeY());
        }
    }
}

void analyzeKey(unsigned char key)
{
    switch (key)
    {
    case 'a':
    case 'A':
        glTranslatef(0.2, 0.0, 0.0);
        break;
    case 'd':
    case 'D':
        glTranslatef(-0.2, 0.0, 0.0);
        break;
    case 'w':
    case 'W':
        glTranslatef(0.0, -0.2, 0.0);
        break;
    case 's':
    case 'S':
        glTranslatef(0.0, 0.2, 0.0);
        break;
        //
    case '-':
        glTranslatef(0.0, 0.0, -0.2);
        break;
    case '=':
        glTranslatef(0.0, 0.0, 0.2);
        break;
        //
    case 't':
    case 'T':
        glRotatef(-3.0, 1.0, 0.0, 0.0);
        break;
    case 'g':
    case 'G':
        glRotatef(3.0, 1.0, 0.0, 0.0);
        break;
    case 'f':
    case 'F':
        glRotatef(-3.0, 0.0, 1.0, 0.0);
        break;
    case 'h':
    case 'H':
        glRotatef(3.0, 0.0, 1.0, 0.0);
        break;
    case (char)27:
        glutLeaveMainLoop();
    }
}

void drawCoordinatePlane()
{
    glColor3f(0.0, 0.0, 0.0);

    glBegin(GL_LINES);

    glVertex2f(ptr->left(), 0);
    glVertex2f(ptr->right(), 0);

    glVertex2f(0, ptr->top());
    glVertex2f(0, ptr->bot());

    glVertex3f(0, 0, -5);
    glVertex3f(0, 0, 5);

    glEnd();
}

void showLocalization()
{
    glClear(GL_COLOR_BUFFER_BIT);

    drawCoordinatePlane();

    glBegin(GL_QUADS);

    GLshowSCs();

    glEnd();

    glutSwapBuffers();
}

void keyboardLocalization(unsigned char key, int x, int y)
{
    analyzeKey(key);
    showLocalization();
}

void showBalancingMethod()
{
    glClear(GL_COLOR_BUFFER_BIT);

    drawCoordinatePlane();

    glBegin(GL_QUADS);

    GLshowSCs();

    glColor3f(ptr->getColors()[ptr->getSCs().size()][0], ptr->getColors()[ptr->getSCs().size()][1], ptr->getColors()[ptr->getSCs().size()][2]);
    for (auto& keyValue : ptr->getInvariantMeasure())
    {
        float x, y;
        ptr->getLeftTopXY(x, y, keyValue.first);

        glVertex3f(x, y,                                                keyValue.second);
        glVertex3f(x + ptr->getCellSizeX(), y,                          keyValue.second);
        glVertex3f(x + ptr->getCellSizeX(), y - ptr->getCellSizeY(),    keyValue.second);
        glVertex3f(x, y - ptr->getCellSizeY(),                          keyValue.second);
    }

    glEnd();

    glutSwapBuffers();
}

void keyboardBalancingMethod(unsigned char key, int x, int y)
{
    analyzeKey(key);
    showBalancingMethod();
}

void showJohnsonAlgorithm()
{
    glClear(GL_COLOR_BUFFER_BIT);

    drawCoordinatePlane();

    glBegin(GL_QUADS);

    GLshowSCs();

    float raising = 3.0f;

    glColor3f(1, 0, 0);
    for (auto& keyValue : ptr->getGraphForMaxCycle())
    {
        float x, y;
        ptr->getLeftTopXY(x, y, keyValue.first);

        glVertex3f(x, y,                                                raising);
        glVertex3f(x + ptr->getCellSizeX(), y,                          raising);
        glVertex3f(x + ptr->getCellSizeX(), y - ptr->getCellSizeY(),    raising);
        glVertex3f(x, y - ptr->getCellSizeY(),                          raising);
    }

    glEnd();

    glutSwapBuffers();
}

void keyboardJohnsonAlgorithm(unsigned char key, int x, int y)
{
    analyzeKey(key);
    showJohnsonAlgorithm();
}

void showRomanovskyAlgorithm()
{
    glClear(GL_COLOR_BUFFER_BIT);

    drawCoordinatePlane();

    glBegin(GL_QUADS);

    GLshowSCs();

    float raising = 0.0f;

    glColor3f(0, 0, 1);
    for (auto& circuit : ptr->RomanovskyAlgorithm::getMinCircuits())
    {
        for (auto& cell : circuit)
        {
            float x, y;
            ptr->getLeftTopXY(x, y, cell);

            glVertex3f(x, y,                                                raising);
            glVertex3f(x + ptr->getCellSizeX(), y,                          raising);
            glVertex3f(x + ptr->getCellSizeX(), y - ptr->getCellSizeY(),    raising);
            glVertex3f(x, y - ptr->getCellSizeY(),                          raising);
        }
    }

    glColor3f(1, 0, 0);
    for (auto& circuit : ptr->RomanovskyAlgorithm::getMaxCircuits())
    {
        for (auto& cell : circuit)
        {
            float x, y;
            ptr->getLeftTopXY(x, y, cell);

            glVertex3f(x, y,                                                raising);
            glVertex3f(x + ptr->getCellSizeX(), y,                          raising);
            glVertex3f(x + ptr->getCellSizeX(), y - ptr->getCellSizeY(),    raising);
            glVertex3f(x, y - ptr->getCellSizeY(),                          raising);
        }
    }

    glEnd();

    glutSwapBuffers();
}

void keyboardRomanovskyAlgorithm(unsigned char key, int x, int y)
{
    analyzeKey(key);
    showRomanovskyAlgorithm();
}
