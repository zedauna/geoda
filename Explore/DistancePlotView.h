#ifndef __DISTANCE_PLOT_VIEW_H__
#define __DISTANCE_PLOT_VIEW_H__

#include <map>
#include "ScatterNewPlotView.h"
#include "LoessPlotCanvas.h"
#include "../DialogTools/AbstractClusterDlg.h"

class DistancePlot;

class DistancePlotCanvas : public LoessPlotCanvas
{
    DECLARE_CLASS(DistancePlotCanvas)
    bool use_def_y_range;

    double prev_y_axis_min;
    double prev_y_axis_max;

    double y_axis_min;
    double y_axis_max;

    const static int default_style;

public:
    DistancePlotCanvas(wxWindow *parent, TemplateFrame* t_frame,
                       Project* project,
                       const std::vector<double>& X,
                       const std::vector<double>& Y,
                       const std::vector<bool>& X_undef,
                       const std::vector<bool>& Y_undef,
                       double x_min, double x_max,
                       double y_min, double y_max,
                       const wxString& X_label,
                       const wxString& Y_label,
                       const wxPoint& pos = wxDefaultPosition,
                       const wxSize& size = wxDefaultSize);

    virtual ~DistancePlotCanvas();

    virtual void DisplayRightClickMenu(const wxPoint& pos);

    virtual void update(HLStateInt* o) {}

    virtual void UpdateSelection(bool shiftdown, bool pointsel) {} // do nothing

	virtual void DrawHighlightedShapes(wxMemoryDC &dc) {} // do nothing

    void OnSaveResult(wxCommandEvent& event);

    void OnUseAdjustYAxis(wxCommandEvent& event);

    void OnAdjustYAxis(wxCommandEvent& event);

    void OnToggleDataPoints(wxCommandEvent& event);

    void OnToggleConfidenceInterval(wxCommandEvent& event);

    void SetCheckMarks(wxMenu* menu);
    
    DECLARE_EVENT_TABLE()
};

class DistancePlotFrame : public TemplateFrame
{
    DECLARE_CLASS(DistancePlotFrame)
public:
    DistancePlotFrame(wxFrame *parent, Project* project,
                      const std::vector<double>& X,
                      const std::vector<double>& Y,
                      const std::vector<bool>& X_undef,
                      const std::vector<bool>& Y_undef,
                      double x_min, double x_max,
                      double y_min, double y_max,
                      const wxString& X_label,
                      const wxString& Y_label,
                      const wxString& title,
                      const wxPoint& pos = wxDefaultPosition,
                      const wxSize& size = wxSize(900,800),
                      const long style = wxDEFAULT_FRAME_STYLE);

    virtual ~DistancePlotFrame();

    virtual void OnActivate(wxActivateEvent& event);

    virtual void OnMouseEvent(wxMouseEvent& event);

    virtual void OnRightClick(const wxPoint& pos);

    virtual void UpdateOptionMenuItems();

    virtual void UpdateContextMenuItems(wxMenu* menu);


    DECLARE_EVENT_TABLE()
};




class DistancePlotDlg : public AbstractClusterDlg
{
public:
    DistancePlotDlg(wxFrame* parent, Project* project);
    virtual ~DistancePlotDlg();
    
    void OnCancelBtn(wxCommandEvent& ev);
    void OnOK(wxCommandEvent& ev);

    void OnAllPairsRadioSelected(wxCommandEvent& ev);
    void OnRandSampRadioSelected(wxCommandEvent& ev);
    void OnThreshCheckBox(wxCommandEvent& ev);
    void OnThreshTextCtrl(wxCommandEvent& ev);
    void OnThreshSlider(wxCommandEvent& ev);
    void OnMaxIterTextCtrl(wxCommandEvent& ev);
    void OnMaxDistanceTextCtrl(wxCommandEvent& ev);
    void OnMaxIterTctrlKillFocus(wxFocusEvent& ev);
    void OnSeedCheck(wxCommandEvent& ev);
    void OnDistanceChoiceSelected(wxCommandEvent& ev);
    void OnChangeSeed(wxCommandEvent& ev);
    void OnMaxDistMethodChoice(wxCommandEvent& ev);

    void UpdateEstPairs();
    void OnClose(wxCloseEvent& ev);
    virtual wxString _printConfiguration();
    
    DistancePlot* GetDistancePlot();
    wxString title;
    wxString str_threshold;

protected:
    DistancePlot* distplot;

    wxStaticText* vardist_txt; //
    wxChoice* vardist_choice; //
    wxStaticText* dist_txt; // ID_DIST_TXT
    wxChoice* dist_choice; // ID_DIST_CHOICE
    wxCheckBox* thresh_cbx; // ID_THRESH_CBX
    wxTextCtrl* thresh_tctrl; // ID_THRESH_TCTRL
    wxSlider* thresh_slider; // ID_THRESH_SLDR
    wxRadioButton* all_pairs_rad; // ID_ALL_PAIRS_RAD
    wxStaticText* est_pairs_txt; // ID_EST_PAIRS_TXT
    wxStaticText* est_pairs_num_txt; // ID_EST_PAIRS_NUM_TXT
    wxRadioButton* rand_samp_rad; // ID_RAND_SAMP_RAD
    wxStaticText* max_iter_txt; // ID_MAX_ITER_TXT
    wxTextCtrl* max_iter_tctrl; // ID_MAX_ITER_TCTRL
    //wxListBox* combo_var;
    wxChoice* maxdist_choice;

    wxButton* help_btn; // ID_HELP_BTN
    wxButton* apply_btn; // ID_APPLY_BTN

    wxCheckBox* chk_seed;
    wxButton* seedButton;
    static const long sldr_tcks = 1000;

    void CreateControls();

    std::map<wxString, wxString> name_to_nm;
    std::map<wxString, int> name_to_tm_id;

    bool IsArc();
    bool IsMi();
    /** min according to current arc/euc and units */
    double GetThreshMin();
    /** max according to current arc/euc and units */
    double GetThreshMax();



    void InitVariableCombobox(wxListBox* var_box);

    void GetSelectedVariables(wxListBox* var_box,
                              std::vector<std::vector<double> >& data,
                              std::vector<std::vector<bool> >& data_undefs);

    void UpdateThreshTctrlVal();

    DECLARE_EVENT_TABLE()
};

#endif
