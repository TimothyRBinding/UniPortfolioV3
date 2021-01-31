;;;----------------

;;;- DEFFUNCTIONS -

;;;----------------

(deffunction display-question-input-answer (?question $?allowed-values)
   (printout t ?question) ;;;Text in the first part will be the question
   (bind ?answer (read)) ;;;The answer will take this in as the answer

   (if (lexemep ?answer)
       then (bind ?answer (lowcase ?answer)))

   (while (not (member ?answer ?allowed-values)) do
      (printout t ?question)
      (bind ?answer (read))

      (if (lexemep ?answer) 
          then (bind ?answer (lowcase ?answer))))?answer)

;;;----------------

;;;- QUERY RULES -

;;;----------------

	;;;- Hydrological survey RULES -

(defrule check-hydrological-survey ""
	(not (location-suitability ?)) 
   =>
   (assert (hydrological-survey 
		(display-question-input-answer "What are the results of the hydrological survey? 
		(erosion, significant run-off, flooding, minimal effect or no effect)
		" erosion significant run off flooding minimal no))))
					
	;;;- Energy production RULES -				
	
(defrule check-energy-production ""
	(or (hydrological-survey minimal) (hydrological-survey no))
	(not (location-suitability ?))
   =>
   (assert (energy-production
		(display-question-input-answer "What is the energy production level of the area? 
		(low / medium / high)
		" low medium high))))
					
	;;;- Wildlife score RULES -
	
(defrule check-wildlife-score ""
	(or (energy-production medium) (energy-production high))
	(not (location-suitability ?))
	=>
	(printout t "How many endangered animals are in the vicinity:")
      (bind ?num-endangered-ani (read-number)) ;;;change when done
      (printout t"How many scarce animals are in the area:")
      (bind ?num-scarce-ani(read-number))
      (printout t"How many common animals can be around the area:")
      (bind ?num-common-ani(read-number))
	  
	(bind ?total(+ (* ?num-endangered-ani 3) (* ?num-scarce-ani 2) (* ?num-common-ani 1)))
    (if (>= ?total 20)
        then
		(assert(wildlife-score twenty-or-more)))
			
    (if(and(< ?total 20) (> ?total 10))
    	then
		(assert(wildlife-score between-ten-and-twenty)))
			
	(if(<= ?total 10)
        then
		(assert(wildlife-score ten-or-less)))
	)
	
	;;;- Visual impact RULES -

(defrule check-visual-impact ""
	(or (wildlife-score ten-or-less)(wildlife-score between-ten-and-twenty))
	(not (location-suitability ?))
	=>
	(assert (visual-impact
		(display-question-input-answer "What is the visual impact to the countryside? 
		(close / fairly distant / very distant)
		" close fairly very))))
		
	;;;- Sound impact RULES -

(defrule check-sound-impact ""
	(or(and(wildlife-score ten-or-less)(visual-impact close))(and (visual-impact very) (wildlife-score between-ten-and-twenty)))
	
	(not (location-suitability ?))
	=>
	(assert (sound-impact
		(display-question-input-answer "What is the impact of the sound to the local populace? 
		(quiet / loud)
		" quiet loud))))
	
	;;;- Geological survey RULES -
	
(defrule check-geological-survey ""
	(or(or
	(and
		(and(wildlife-score ten-or-less)(visual-impact close))
		(sound-impact quiet))
		
		(and(wildlife-score ten-or-less)
			(or(visual-impact fairly)(visual-impact very)))
	
	(or(and
		(and(visual-impact very)(wildlife-score between-ten-and-twenty))(sound-impact quiet))
		
		(and(wildlife-score between-ten-and-twenty)
			(or(visual-impact fairly)(visual-impact close))))))

	(not (location-suitability ?))
	=>
	(assert (geological-survey
		(display-question-input-answer "What was the results of the geological survey? 
		(stable / partly stable / unstable)
		" stable partly unstable))))
	
;;;----------------

;;;- REJECT RULES -

;;;----------------

	;;;- Hydrological survey REJECT -

(defrule hydrological-survey-result-erosion ""
	(hydrological-survey erosion)
	(not (location-suitability ?))
	=>
	(assert (location-suitability "Reject : Completely unsuitable due to likelihood of land erosion.")))
	
(defrule hydrological-survey-reject-run-off-or-flooding ""
	(or (or(hydrological-survey significant)(hydrological-survey run)(hydrological-survey off)) (hydrological-survey flooding))
	
	(not (location-suitability ?))
	=>
	(assert (location-suitability "Reject : Completely unsuitable due to risk of flooding.")))

	;;;- Energy production -
	
(defrule energy-production-reject""
	(energy-production low)
	(not (location-suitability ?))
	=>
	(assert (location-suitability "Reject : Completely unsuitable due to not being profitable.")))
	
	;;;- Wildlife score RULES -
	
(defrule wildlife-score-reject ""
	(wildlife-score twenty-or-more)
	(not (location-suitability ?))
	=>
	(assert (location-suitability "Reject : Completely unsuitable due to wildlife impact.")))
	
	;;;- Sound impact RULES -
	
(defrule sound-impact-reject ""
	(sound-impact loud)
	(not (location-suitability ?))
	=>
	(assert (location-suitability "Reject : Completely unsuitable due to impact on population.")))
	
	;;;- Geological survey RULES -
	
(defrule geological-survey-reject ""
	(geological-survey unstable)
	(not (location-suitability ?))
	=>
	(assert (location-suitability "Reject : Completely unsuitable due to unstable ground.")))

;;;----------------

;;;- ACCEPT RULES -

;;;----------------

	;;;- One of the best results -

(defrule best-result-accept ""
	(wildlife-score ten-or-less)
	(energy-production high)
	(visual-impact very)
	(geological-survey stable)
	(not (location-suitability ?))
	=>
	(assert (location-suitability "Accept as one of the best locations : An ideal location. Start building it now.")))
	
(defrule adequate-result1-accept ""
	(and(wildlife-score ten-or-less)
		(visual-impact very)
		(energy-production medium)
		(geological-survey stable))
	(not (location-suitability ?))
	=>
	(assert (location-suitability "Accept as one of the best results possible : An adequate location for a wind farm.")))

(defrule adequate-result2-accept ""
	(and(wildlife-score between-ten-and-twenty)
		(or(or(visual-impact fairly)(visual-impact close))
			(and(visual-impact very)(sound-impact quiet)))
		(energy-production medium)
		(geological-survey stable))
	(not (location-suitability ?))
	=>
	(assert (location-suitability "Accept as one of the best results possible : An adequate location for a wind farm. Consider creating an alternative wildlife habitat.")))

(defrule adequate-result3-accept ""
	(and(wildlife-score between-ten-and-twenty)
		(or(or(visual-impact fairly)(visual-impact close))
			(and(visual-impact very)(sound-impact quiet)))
		(energy-production medium)
		(geological-survey partly))
	(not (location-suitability ?))
	=>
	(assert (location-suitability "Accept as one of the best results possible : An adequate location for a wind farm. Consider creating an alternative wildlife habitat. Requires stabilization.")))

(defrule adequate-result4-accept ""
	(and (wildlife-score ten-or-less)
	(or
		(and(visual-impact close)(sound-impact quiet))
		(energy-production medium)
		(visual-impact fairly))
		(geological-survey partly))
	(not (location-suitability ?))
	=>
	(assert (location-suitability "Accept as one of the best results possible : An adequate location for a wind farm. Requires stabilization.")))

(defrule adequate-result5-accept ""
	(and (wildlife-score ten-or-less)
	(or
		(and(visual-impact close)(sound-impact quiet))
		(energy-production medium)
		(visual-impact fairly))
		(geological-survey stable))
	(not (location-suitability ?))
	=>
	(assert (location-suitability "Accept as one of the best results possible : An adequate location for a wind farm.")))
	
	;;;- Second best results -
	
(defrule second-best-result1-accept ""
	(and(wildlife-score ten-or-less)
		(visual-impact very)
		(geological-survey partly))
	=>
	(assert (location-suitability "Accept as second best : An adequate location for a wind farm. Requires stabilization.")))

(defrule second-best-result2-accept ""
	(and (wildlife-score ten-or-less)
	(or
		(and(visual-impact close)(sound-impact quiet))
		(energy-production high)
		(visual-impact fairly))
		(geological-survey partly))
	(not (location-suitability ?))
	=>
	(assert (location-suitability "Accept as second best : An adequate location for a wind farm. Requires stabilization.")))

(defrule second-best-result3-accept ""
	(and (wildlife-score ten-or-less)
	(or
		(and(visual-impact close)(sound-impact quiet))
		(energy-production high)
		(visual-impact fairly))
		(geological-survey stable))
	(not (location-suitability ?))
	=>
	(assert (location-suitability "Accept as second best : An adequate location for a wind farm.")))
	
(defrule second-best-result4-accept ""
	(and(wildlife-score between-ten-and-twenty)
		(or(or(visual-impact fairly)(visual-impact close))
			(and(visual-impact very)(sound-impact quiet)))
		(energy-production high)
		(geological-survey stable))
	(not (location-suitability ?))
	=>
	(assert (location-suitability "Accept as second best : An adequate location for a wind farm. Consider creating an alternative wildlife habitat.")))

(defrule second-best-result5-accept ""
	(and(wildlife-score between-ten-and-twenty)
		(or(visual-impact fairly)(visual-impact close))
		(energy-production high)
		(geological-survey partly))
	(not (location-suitability ?))
	=>
	(assert (location-suitability "Accept as second best : An adequate location for a wind farm. Consider creating an alternative wildlife habitat. Requires stabilization.")))

;;;-------------------------------

;;;- PROGRAMME RUN AND END RULES -

;;;-------------------------------

(defrule system-banner ""
  (declare (salience 10))
  =>
  (printout t crlf crlf)
  (printout t "The Windy Expert System")
  (printout t crlf crlf))
  
(defrule print-location-suitability ""
  (declare (salience 10))
  (location-suitability ?result)
  =>
  (printout t crlf crlf)
  (printout t "Location suitability: ")
  (printout t crlf crlf)
  (format t " %s%n%n%n" ?result))